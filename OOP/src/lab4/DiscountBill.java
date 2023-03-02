package lab4;

import ua.opnu.java.inheritance.bill.Employee;
import ua.opnu.java.inheritance.bill.GroceryBill;
import ua.opnu.java.inheritance.bill.Item;

public class DiscountBill extends GroceryBill {
    private boolean regularCustomer;
    private int discountCount;
    private double discountAmount;
    public DiscountBill (Employee clerk, boolean regularCustomer) {
        super(clerk);
        this.regularCustomer = regularCustomer;
        this.discountCount = 0;
        this.discountAmount = 0;
    }

    public int getDiscountCount() {
        return discountCount;
    }
    public double getDiscountAmount() {
        return discountAmount;
    }
    @Override
    public double getTotal() {
        return super.getTotal() - getDiscountAmount();
    }
    public double getDiscountPercent() {
        return 100 - ((getTotal()) * 100 ) / super.getTotal();
    }

    @Override
    public void add(Item i) {
        super.add(i);
        if (regularCustomer && i.getDiscount() > 0) {
            discountAmount = discountAmount + i.getDiscount();
            discountCount++;
        }
    }
}
