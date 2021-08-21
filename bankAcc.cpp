#include<iostream>
    using namespace std;

    class Account{
      
    private:
    float balance;
    float amount_to_deposit;

    public:

    float check_balance();
    void deposit_to_account();
    void withdraw_from_account();

    };
    float Account::check_balance(){

    return balance;
    }
    void Account::deposit_to_account(){
         float amount_to_deposit;

          cout<<"how much to deposit:kshs."; cin>>amount_to_deposit;

          balance += amount_to_deposit;
    }
    void Account::withdraw_from_account(){
          float amount_to_withdraw;

          cout<<"how much to withdraw:kshs."; cin>>amount_to_withdraw;

          balance = balance-amount_to_withdraw;
 }

        main(){

        Account acc;
        float balance;
        acc.deposit_to_account();
        acc.withdraw_from_account();
        balance=acc.check_balance();
        cout<<"the balance is:"<<balance<<endl; }
