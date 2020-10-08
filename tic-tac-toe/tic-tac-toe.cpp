class TicTacToe
{
public:
  /** Initialize your data structure here. */
  TicTacToe(int n)
  {
    board.resize(n, vector<int>(n, 0));
  }

  int move(int row, int col, int player)
  {
    board[row][col] = player;
    int i = 0, j = 0, n = board.size();
    for (j = 1; j < n; ++j)
    {
      if (board[row][j] != board[row][j - 1])
        break;
    }
    if (j == n)
      return player;
    for (i = 1; i < n; ++i)
    {
      if (board[i][col] != board[i - 1][col])
        break;
    }
    if (i == n)
      return player;
    if (row == col)
    {
      for (i = 1; i < n; ++i)
      {
        if (board[i][i] != board[i - 1][i - 1])
          break;
      }
      if (i == n)
        return player;
    }
    if (row + col == n - 1)
    {
      for (i = 1; i < n; ++i)
      {
        if (board[n - i - 1][i] != board[n - i][i - 1])
          break;
      }
      if (i == n)
        return player;
    }
    return 0;
  }

private:
  vector<vector<int>> board;
};