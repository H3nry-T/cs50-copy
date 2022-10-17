def makeGrid(row, column):
    rows = []
    for i in range(row):
        columns = []
        for j in range(column - 1):
            columns.append(j + 1)
        rows.append(columns)
    return rows

print(makeGrid(3, 4))
