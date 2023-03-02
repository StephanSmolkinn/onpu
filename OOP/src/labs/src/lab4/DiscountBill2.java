package labs.src.lab4;

import ua.opnu.java.inheritance.bill.Employee;
import ua.opnu.java.inheritance.bill.GroceryBill;
import ua.opnu.java.inheritance.bill.Item;

public class DiscountBill2 {
    private Employee clerk;
    private GroceryBill discountBill2;

    private boolean regularCustomer;
    private int discountCount;
    private double discountAmount;

    public DiscountBill2 (Employee clerk, boolean regularCustomer) {
        this.clerk = clerk;
        discountBill2 = new GroceryBill(clerk);
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
    public double getTotal() {
        return discountBill2.getTotal() - getDiscountAmount();
    }
    public double getDiscountPercent() {
        return 100 - ((getTotal()) * 100 ) / discountBill2.getTotal();
    }
    public void add(Item i) {
        discountBill2.add(i);
        if (regularCustomer && i.getDiscount() > 0) {
            discountAmount = discountAmount + i.getDiscount();
            discountCount++;
        }
    }
}
