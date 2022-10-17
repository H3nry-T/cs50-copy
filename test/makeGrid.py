def makeGrid(row, column):
    rows = []
    for i in range(row):

        columns = []
        for j in range(column):
            columns.append(j)
        rows.append(columns)
    return rows

print(makeGrid(3, 4))