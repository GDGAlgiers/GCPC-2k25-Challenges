import sys

def is_winning_move(moves):
    board = [['' for _ in range(3)] for _ in range(3)]

    # Fill the board based on the move list
    for i, (r, c) in enumerate(moves):
        player = 'X' if i % 2 == 0 else 'O'
        board[r][c] = player

    # Identify the last move and the player who made it
    last_row, last_col = moves[-1]
    last_player = 'X' if (len(moves) - 1) % 2 == 0 else 'O'

    # Check row
    if all(board[last_row][col] == last_player for col in range(3)):
        return True

    # Check column
    if all(board[row][last_col] == last_player for row in range(3)):
        return True

    # Check main diagonal
    if last_row == last_col:
        if all(board[i][i] == last_player for i in range(3)):
            return True

    # Check anti-diagonal
    if last_row + last_col == 2:
        if all(board[i][2 - i] == last_player for i in range(3)):
            return True

    return False

if __name__ == "__main__":
    # Expecting input in format like: 0 0\n0 1\n0 2\n...
    moves = []
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        r, c = map(int, line.split())
        moves.append((r, c))

    print(is_winning_move(moves))
