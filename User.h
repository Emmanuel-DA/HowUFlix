#ifndef USER_H
#define USER_H

class User{
  public:
    User();
    User(string, string, string, string);
    void PrintUserInfo() const;
  private:
    string name;
    string name1;
    string ID;
    string Pname;
};
#endif