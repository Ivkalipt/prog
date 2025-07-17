def find_permutation(s):
    """
    Находит перестановку строки, в которой буквы в соответствующих позициях 
    исходной и новой строки не совпадают.

    Args:
        s: Исходная строка.

    Returns:
        Перестановка строки, если она существует, иначе "No solution".
    """

    n = len(s)
    permutation = list(s)

    # Ищем первую букву, которую можно поменять местами
    for i in range(n):
        if i + 1 < n and permutation[i] != permutation[i + 1]:
            # Меняем местами текущую букву с следующей
            permutation[i], permutation[i + 1] = permutation[i + 1], permutation[i]
            return "".join(permutation)

    # Если не нашли букву для перестановки, значит, решения нет
    return "No solution"

print(find_permutation(input()))