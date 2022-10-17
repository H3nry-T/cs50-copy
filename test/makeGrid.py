def makeGrid(row, column):
    rows = []
    columns = []
    for i in range(row):

        for j in range(column):
            columns.append(j)
        rows.append(columns)
    return rows

print(makeGrid(3, 4))