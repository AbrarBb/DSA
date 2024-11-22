
class Account
{
  String accountHolder='';
  int age=0;
  String address='';
  int accountNumber=0;
  void detailprint()
  {
    print(accountHolder);
    
  }
}

void main()
{
  Account firstCustomer=Account();
  //Account l=Account();
 print('Enter Your Name:');
  String name = stdin.readLineSync() ?? '';
  
  a.accountHolder=name;
  
  a.detailprint();
}