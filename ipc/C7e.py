def count_crossings(river_description):
    """
    Подсчитывает минимальное количество переправ через реку и ее притоки.

    Args:
        river_description: Строка, описывающая притоки реки (L - левый, R - правый, B - оба берега).

    Returns:
        Минимальное количество переправ.
    """

    crossings = 0
    current_side = 'L'  # Начальное положение - левый берег

    for bank in river_description:
        if bank == 'L':
            if current_side == 'R':
                crossings += 1
            current_side = 'L'
        elif bank == 'R':
            if current_side == 'L':
                crossings += 1
            current_side = 'R'
        elif bank == 'B':
            crossings += 1
            current_side = 'R' if current_side == 'L' else 'L'

    # Переправа в конечную точку
    if current_side == 'L':
        crossings += 1

    return crossings

# Чтение входных данных


# Подсчет переправ


# Вывод результата в файл
print(count_crossings(input()))