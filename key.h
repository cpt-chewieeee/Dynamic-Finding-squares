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




#endif
~/cs141/proj2/new/tar
hzhan014@well $ git remote add origin https://github.com/cpt-chewieeee/chromosome.git
fatal: Not a git repository (or any parent up to mount point /home/csmajs)
Stopping at filesystem boundary (GIT_DISCOVERY_ACROSS_FILESYSTEM not set).
~/cs141/proj2/new/tar
hzhan014@well $ ls
hzhan014_lab2.tgz  key.h     output.txt   readme.txt
input2.txt*        makefile  problem.txt  square.cc
~/cs141/proj2/new/tar
hzhan014@well $ cat key.h 
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




#endif