def min_additional_lamps(x, y, k, l):
    start = min(x, y)
    end = max(x, y)

    # Нахождение первой и последней позиции фонарей
    first_lamp_pos = ((start + k - 1) // k) * k  # округление вверх
    last_lamp_pos = (end // k) * k  # округление вниз

    # Счетчик дополнительных фонарей
    additional_lamps = 0

    # Проверка области перед первым фонарем
    if first_lamp_pos > start:
        # Темный участок от start до first_lamp_pos - l
        dark_start = start
        dark_end = first_lamp_pos - l
        
        if dark_end >= dark_start:
            # Количество фонарей, необходимых для освещения этого участка
            additional_lamps += (dark_end - dark_start + k) // k

    # Проверка области после последнего фонаря
    if last_lamp_pos < end:
        # Темный участок от last_lamp_pos + l до end
        dark_start = last_lamp_pos + l
        dark_end = end
        
        if dark_end >= dark_start:
            # Количество фонарей, необходимых для освещения этого участка
            additional_lamps += (dark_end - dark_start + k) // k

    return additional_lamps

# Чтение входных данных
x, y, k, l = map(int, input().split())
print(min_additional_lamps(x, y, k, l))
