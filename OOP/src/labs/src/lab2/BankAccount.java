package labs.src.lab2;

public class BankAccount {

    String name;
    double balance;
    double transactionFee = 0;

    void deposit(double amount) {
        if (amount > 0)
            balance = balance + amount;
    }

    double getBalance() {
        return this.balance;
    }

    boolean withdraw(double amount) {
        if (amount > 0)
            balance = (balance - amount) - transactionFee;

        if (balance < 0) {
            balance = (balance + amount) + transactionFee;
            return false;
        }

        return true;
    }

    boolean transfer(BankAccount receiver, double amount) {
        if (balance < amount + transactionFee) {
            return false;
        }

        if (amount > 0) {
            receiver.balance = receiver.balance + amount;
            balance = balance - amount - transactionFee;
            return true;
        }

        return false;
    }

}
