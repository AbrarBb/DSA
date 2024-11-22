import 'dart:io';

class Account 
{
  String accountHolder;
  int age;
  String address;
  int accountNumber;

  Account({
    required this.accountHolder,
    required this.age,
    required this.address,
    required this.accountNumber,
  });

  void detailprint() 
  {
    print('Account Details:');
    print('Name: $accountHolder');
    print('Age: $age');
    print('Address: $address');
    print('Account Number: $accountNumber');
  }
}

void main() 
{
  print('Enter Your Name:');
  String name = stdin.readLineSync() ?? '';

  print('Enter Your Age:');
  int age = int.tryParse(stdin.readLineSync() ?? '') ?? 0;

  print('Enter Your Address:');
  String address = stdin.readLineSync() ?? '';

  print('Enter Your Account Number:');
  int accountNumber = int.tryParse(stdin.readLineSync() ?? '') ?? 0;


  Account account = Account(
    accountHolder: name,
    age: age,
    address: address,
    accountNumber: accountNumber,
  );

  account.detailprint();
}
