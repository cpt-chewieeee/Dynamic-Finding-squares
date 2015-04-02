#ifndef __KEY_H_
#define __KEY_H_

class Key
{
  public: 
    Key()
    {
      this->row = -1;
      this->col = -1;
    }
    Key(int s, int i)
    {
      this->row = s;
      this->col = i;
    }
    int row;
    int col;
    int compare(const Key k)
    {
      if(this->row == k.row && this->col == k.col) return 1;
      return 0;
    }
    int row_value() const
    {
      return row;
    }
    int col_value() const
    {
      return col;
    }
    bool operator<(const Key& k) const
    {
      //int s_cmp = this->s.compare(k.s);
      //if(s_cmp == 0)
      //{
        return (this->row, this->col);
      //}
      //return s_cmp < 0;
    }

    
};

