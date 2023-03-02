package lab3;

public class BankAccount {
    private String name;
    private double balance;
    private double transactionFee = 0;

    public void deposit(double amount) {
        if (amount > 0)
            balance = balance + amount;
    }

    public double getBalance() {
        return this.balance;
    }

    public boolean withdraw(double amount) {

        if (amount > 0)
            balance = (balance - amount) - transactionFee;

        if (balance < 0) {
            balance = (balance + amount) + transactionFee;
            return false;
        }

        return true;

    }

    public boolean transfer(BankAccount receiver, double amount) {

        if (balance < amount + transactionFee)
            return false;

        if (amount > 0) {
            receiver.balance = receiver.balance + amount;
            balance = balance - amount - transactionFee;

            return true;
        }

        return false;

    }
}
