def initialize_table(n):
    table = []      #Initialize all elements table with 0
    for _ in range(n):
        row = [0] * n
        table.append(row)
    return table

def check_valid(table, row, col , n):
    for i in range(col):
        if table[row][i] == 1:
            return False #Checking if there is queen in same left row

    for i ,j in zip(range(row, -1, -1), range(col, -1, -1)):
        if table[i][j] == 1:
            return False #Checking if there is queen in upper left diagonale

    for i ,j  in zip(range(row, n, 1), range(col, -1, -1)):
        if table[i][j] == 1:
            return False #Checking if there is queen in down left diagonale

    return True

def replace_queens(table, col, n, solutions):
    if col == n:            #If all queens are placed so we add  current table to solutions
        solutions.append([list(row) for row in table])
        return 1

    count_solutions = 0

    for i in range(n):
        if check_valid(table, i, col, n):
            table[i][col] = 1     #
            count_solutions += replace_queens(table, col + 1, n, solutions)
            table[i][col] = 0  #Backtrack (remove)
    return count_solutions

def get_solutions(n):
    table = initialize_table(n)  # Initialize chess table
    solutions = []
    count = replace_queens(table, 0, n, solutions)
    return count, solutions

def print_result(solutions):
    for i in solutions:
        for row in i:
            print(row)
        print("\n")

def nqueens():
    n = int(input("Enter  number of your queens : "))
    count, solutions = get_solutions(n)
    if count != 0:
        print(" This is all possible solutions : \n")
        print_result(solutions)
        print(f" Solution number for your {n}-Queens problem : {count}\n")
    else:
        print(" There is no solutions. ")


nqueens()