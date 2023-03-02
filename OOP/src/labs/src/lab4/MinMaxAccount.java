package labs.src.lab4;

import ua.opnu.java.inheritance.account.BankingAccount;
import ua.opnu.java.inheritance.account.Credit;
import ua.opnu.java.inheritance.account.Debit;
import ua.opnu.java.inheritance.account.Startup;

public class MinMaxAccount extends BankingAccount {
    private int min;
    private int max;
    public MinMaxAccount(Startup s) {
        super(s);
        this.min = s.getBalance();
        this.max = s.getBalance();
    }

    public int getMin() {
        return min;
    }

    public int getMax() {
        return max;
    }

    @Override
    public void debit(Debit d) {
        super.debit(d);
        if(max < getBalance())
            max = getBalance();
    }
    @Override
    public void credit(Credit c) {
        super.credit(c);
        if(min > getBalance())
            min = getBalance();
    }
}
