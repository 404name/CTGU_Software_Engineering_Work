package orderSystem.behavior.activity;

import orderSystem.behavior.Activity;

/**
 * @program: algorithm
 * @description:
 * @author: CTGU_LLZ(404name)
 * @create: 2021-11-27 13:15
 **/
public class DoubleEleven implements Activity {
    public DoubleEleven() {
    }

    @Override
    public double getActivityDiscount(double price) {
        System.out.println("参加双十一活动，满400-30");

        double discount = (int)(price/400) * 30;

        System.out.println("本次享受活动优惠" + discount);

        return price - discount;
    }
}
