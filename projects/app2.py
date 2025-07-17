import os
import sys
import csv
import configparser
from barcode import EAN8
from barcode.writer import ImageWriter
from PIL import Image, ImageDraw, ImageFont
from PyQt6.QtCore import Qt, QSize
from PyQt6.QtWidgets import (QApplication, QMainWindow, QPushButton, QLineEdit, 
                            QLabel, QVBoxLayout, QWidget, QComboBox, QMessageBox, QFileDialog)
    

# Определяем базовый путь
def resource_path(relative_path):
    #Получает абсолютный путь к ресурсу для работы и в exe
    if hasattr(sys, '_MEIPASS'):
        return os.path.join(sys._MEIPASS, relative_path)
    return os.path.join(os.path.abspath("."), relative_path)

# Пути к файлам
BASE_DIR = os.path.abspath(".")
CONFIG_PATH = resource_path("config.ini")
TEMPLATE_TITLE = resource_path("list.png")
TEMPLATE_ANS = resource_path("Ans.png")
SAVE_DIR = os.path.join(BASE_DIR, "pictures")
TRASH_DIR = os.path.join(BASE_DIR, "trash")

#Кодировка
Encoding = "utf-8"

class Student:
    def __init__(self, code, first_name, last_name, sur_name, profile, class_, subject):
        self.code = code
        self.first_name = first_name
        self.last_name = last_name
        self.sur_name = sur_name
        self.profile = profile
        self.class_ = class_
        self.subject = subject.lower()

class MainApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.students = []
        self.subjects = set()
        self.selected_subject = ""
        self.config = None
        
        self.init_ui()
        self.check_directories()
        self.load_config()
        
    def init_ui(self):
        self.setWindowTitle("Генератор бланков")
        self.setMinimumSize(QSize(600, 400))
        
        layout = QVBoxLayout()
        
        # Поля ввода
        self.table_path_edit = QLineEdit()
        self.table_path_edit.setPlaceholderText("Путь к таблице (оставьте пустым для текущей папки)")
        
        self.table_name_edit = QLineEdit("table.xlsx")
        
        self.save_path_edit = QLineEdit()
        self.save_path_edit.setPlaceholderText("Путь для сохранения (оставьте пустым для папки 'pictures')")
        
        # Кнопки
        self.load_btn = QPushButton("Загрузить данные")
        self.load_btn.clicked.connect(self.load_data)
        
        self.subject_combo = QComboBox()
        self.subject_combo.currentTextChanged.connect(self.set_subject)
        
        self.generate_btn = QPushButton("Сгенерировать бланки")
        self.generate_btn.clicked.connect(self.generate_blanks)
        
        self.gen_table_btn = QPushButton("Сгенерировать таблицу кодов")
        self.gen_table_btn.clicked.connect(self.generate_code_table)
        
        self.gen_names_btn = QPushButton("Заменить коды на имена")
        self.gen_names_btn.clicked.connect(self.generate_names_table)
        
        # Добавление виджетов
        layout.addWidget(QLabel("Путь к таблице:"))
        layout.addWidget(self.table_path_edit)
        layout.addWidget(QLabel("Имя файла таблицы:"))
        layout.addWidget(self.table_name_edit)
        layout.addWidget(self.load_btn)
        layout.addWidget(QLabel("Предмет:"))
        layout.addWidget(self.subject_combo)
        layout.addWidget(QLabel("Папка для сохранения:"))
        layout.addWidget(self.save_path_edit)
        layout.addWidget(self.generate_btn)
        layout.addWidget(self.gen_table_btn)
        layout.addWidget(self.gen_names_btn)
        
        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)
    
    def check_directories(self):
        #Создает необходимые папки, если их нет
        os.makedirs(SAVE_DIR, exist_ok=True)
        os.makedirs(TRASH_DIR, exist_ok=True)
    
    def load_config(self):
        #Загружает конфигурацию из config.ini
        self.config = configparser.ConfigParser()
        if not os.path.exists(CONFIG_PATH):
            self.show_error("Файл config.ini не найден!")
            return
        
        try:
            self.config.read(CONFIG_PATH)
        except Exception as e:
            self.show_error(f"Ошибка при чтении config.ini: {str(e)}")

    
    def load_data(self):
        #Загрузка данных из таблицы
        if not self.config:
            self.show_error("Конфигурация не загружена!")
            return
            
        table_path = self.table_path_edit.text() or BASE_DIR
        table_name = self.table_name_edit.text()
        full_path = os.path.join(table_path, table_name)
        
        if not os.path.exists(full_path):
            self.show_error(f"Файл не найден: {full_path}")
            return
        
        try:
            self.students = []
            self.subjects = set()
            
            # Получаем номера столбцов из конфига
            cols = self.config["Coloumns"]
            first_name_col = int(cols["FirstName"])
            last_name_col = int(cols["LastName"])
            sur_name_col = int(cols["SurName"])
            profile_col = int(cols["Profile"])
            class_col = int(cols["Class"])
            subject_col = int(cols["Subject"])
            
            start_row = int(self.config["Nums"]["StartStr"])
            
            with open(full_path, mode="r", encoding=Encoding) as file:
                reader = csv.reader(file)
                
                # Пропускаем заголовки и начальные строки
                for _ in range(start_row - 1):
                    next(reader)
                
                class_counts = {}
                
                for row in reader:
                    if len(row) <= max(first_name_col, last_name_col, sur_name_col, 
                                     profile_col, class_col, subject_col):
                        continue
                    
                    class_num = row[class_col][:-1]
                    if class_num not in class_counts:
                        class_counts[class_num] = 1
                    else:
                        class_counts[class_num] += 1
                    
                    student = Student(
                        code=str(class_num).zfill(4) + str(class_counts[class_num]).zfill(3),
                        first_name=row[first_name_col],
                        last_name=row[last_name_col],
                        sur_name=row[sur_name_col],
                        profile=row[profile_col],
                        class_=class_num,
                        subject=row[subject_col]
                    )
                    print(student.code, student.last_name, student.subject) 
                    self.students.append(student)
                    self.subjects.add(student.subject)

            self.subject_combo.clear()
            self.subject_combo.addItems(sorted(self.subjects))
            QMessageBox.information(self, "Успех", f"Загружено {len(self.students)} записей!")
            
        except Exception as e:
            self.show_error(f"Ошибка при чтении файла: {str(e)}")
    
    def set_subject(self, subject):
        self.selected_subject = subject
    
    def generate_blanks(self):
        #Генерация бланков
        if not self.selected_subject:
            self.show_error("Выберите предмет!")
            return
        
        save_path = self.save_path_edit.text() or SAVE_DIR
        
        if not os.path.exists(TEMPLATE_TITLE) or not os.path.exists(TEMPLATE_ANS):
            self.show_error("Шаблоны 'list.png' и 'Ans.png' не найдены!")
            return
        
        try:
            title_img = Image.open(TEMPLATE_TITLE)
            ans_img = Image.open(TEMPLATE_ANS)
            
            # Пробуем загрузить Calibri, если нет используем Arial
            try:
                font = ImageFont.truetype("calibri.ttf", size=100)
            except:
                font = ImageFont.truetype("arial.ttf", size=100)
            
            for student in self.students:
                if student.subject != self.selected_subject:
                    continue
                
                # Генерация штрих-кода
                code_img = self.generate_barcode(student.code)
                
                # Создание бланка
                title_copy = title_img.copy()
                title_copy.paste(code_img, (0, 100))
                
                draw = ImageDraw.Draw(title_copy)
                draw.text((1000, 850), 
                            f"{self.selected_subject.capitalize()}\n\n"
                            f"{student.first_name}\n\n"
                            f"{student.last_name}\n\n"
                            f"{student.sur_name}\n\n"
                            f"{student.class_}",
                            font=font, 
                            fill="#1C0606")
                
                # Сохранение
                output_path = os.path.join(save_path, f"{student.code}_list.png")
                title_copy.save(output_path)
                
                # Бланк ответов
                ans_copy = ans_img.copy()
                ans_copy.paste(code_img, (0, 100))
                ans_copy.save(os.path.join(save_path, f"{student.code}_ans.png"))
            
            QMessageBox.information(self, "Успех", "Бланки успешно сгенерированы!")
            
        except Exception as e:
            self.show_error(f"Ошибка при генерации бланков: {str(e)}")
    
    def generate_barcode(self, code):
        #Генерация изображения штрих-кода
        ean = EAN8(code, writer=ImageWriter())
        temp_path = os.path.join(TRASH_DIR, f"temp_{code}")
        ean.save(temp_path)
        
        img = Image.open(f"{temp_path}.png")
        img = img.crop((0, 0, 350, 200))
        os.remove(f"{temp_path}.png")
        
        return img
    
    def generate_code_table(self):
        #Генерация таблицы с кодами
        if not self.selected_subject:
            self.show_error("Выберите предмет!")
            return
        
        try:
            with open("codes.csv", "w", encoding=Encoding, newline="") as f:
                writer = csv.writer(f)
                writer.writerow(["Предмет", "Код", "Баллы"])
                
                for student in self.students:
                    if student.subject == self.selected_subject:
                        writer.writerow([student.subject, student.code, ""])
            
            QMessageBox.information(self, "Успех", "Таблица codes.csv создана!")
        except Exception as e:
            self.show_error(f"Ошибка при создании таблицы: {str(e)}")
    
    def generate_names_table(self):
        #Замена кодов на имена в таблице
        if not os.path.exists("codes.csv"):
            self.show_error("Файл codes.csv не найден!")
            return
        
        try:
            with open("codes.csv", "r", encoding=Encoding) as infile, \
                open("results.csv", "w", encoding=Encoding, newline="") as outfile:
            
                reader = csv.reader(infile)
                writer = csv.writer(outfile)
            
                headers = next(reader)
                headers = ["Предмет", "Фамилия", "Имя", "Отчество", "Баллы"]
                writer.writerow(headers)
                
                code_to_name = dict()
                
                i = 0

                row = list(reader)
                print(row)

                for student in self.students:
                    if student.subject == self.selected_subject:
                        writer.writerow([student.subject, student.first_name, student.last_name, student.sur_name,  row[i][2]])
                        i += 1

                

                """for s in self.students:
                    code_to_name[s.code] = [s.first_name, s.last_name, s.sur_name]
                    print(s.code)


                    
                # Сопоставляем коды с именами
                
                for row in reader:
                    if len(row) >= 2:
                        
                        if row[1] in code_to_name:
                            code = row[1]
                            res = row[2]
                            print(res)
                            row = [row[0], 0, 0, 0, row[2]]
                            row[1], row[2], row[3] = code_to_name[code]
                            row[4] = res
                            writer.writerow(row)
                            print(row, "\n", code_to_name[code])"""

            
            QMessageBox.information(self, "Успех", "Таблица results.csv создана!")
        except Exception as e:
            self.show_error(f"Ошибка при создании таблицы: {str(e)}")
    
    def show_error(self, message):
        QMessageBox.critical(self, "Ошибка", message)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    # Проверка необходимых файлов
    required_files = [CONFIG_PATH, TEMPLATE_TITLE, TEMPLATE_ANS]
    missing_files = [f for f in required_files if not os.path.exists(f)]
    
    if missing_files:
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Icon.Critical)
        msg.setText("Не найдены необходимые файлы!")
        msg.setInformativeText(f"Отсутствуют: {', '.join(os.path.basename(f) for f in missing_files)}")
        msg.exec()
        sys.exit(1)
    
    window = MainApp()
    window.show()
    sys.exit(app.exec())
