Hongyi Zhang
hzhan014


in my program, i am outputting number of squares but they are overlapped.

psuedocode:


solve(row, col, A[][])={(A[row][col]:row=0 or col=0),
                        (max(1+solve(row, col-1,A)
                             (1+solve(row-1, col, A))
                             (1+solve(row-1, col-1,A))): A[row][col] == F),
                        (max(1+solve(row, col-1,A)
                             (1+solve(row-1, col, A))
                             (1+solve(row-1, col-1,A))): otherwise)}
                            



int solve(const int row, const int col, const vector<vector<int> >&A){


  if(row == 0 || col == 0)  return A[row][col];
  
  if(A[row][col] == 1 && A[row][col-1] == 1 && A[row-1][col-1] ==1 && A[row-1][col] == 1)
    Key t0(row, col-1);
    Key t1(row-1, col);
    Key t2(row-1, col-1);
    dynamic[t0] = 1 + solve(row, col-1, A);
    dynamic[t1] = 1 + solve(row-1, col, A);
    dynamic[t2] = 1 + solve(row-1, col-1, A);
  
  else if(A[row][col] == 1 && (A[row][col-1] ==  0 || A[row-1][col-1] == 0 || A[row-1][col] == 0))
    Key t0(row, col-1);
    Key t1(row-1, col);
    Key t2(row-1, col-1);
    if(A[row][col-1] == 1)  dynamic[t0] = 1 + solve(row, col-1, A);
    else dynamic[t0] = solve(row,col-1,A);
    if(A[row-1][col] == 1)  dynamic[t1] = 1 + solve(row-1, col, A);
    else dynamic[t1] = solve(row-1,col,A);
    if(A[row-1][col-1] == 1)  dynamic[t2] = 1 + solve(row-1, col-1, A);
    else dynamic[t2] = solve(row-1,col-1,A);
  
  else if(A[row][col] == 0)
    Key t3(row, col-1);
    Key t4(row-1, col);
    Key t5(row-1, col-1);
    if(A[row][col-1] == 1)  dynamic[t3] = 1 + solve(row, col-1, A);
    else dynamic[t3] = solve(row,col-1,A);
    if(A[row-1][col] == 1)  dynamic[t4] = 1 + solve(row-1, col, A);
    else dynamic[t4] = solve(row-1,col,A);
    if(A[row-1][col-1] == 1)  dynamic[t5] = 1 + solve(row-1, col-1, A);
    else dynamic[t5] = solve(row-1,col-1,A);
    

return max(dynamic);