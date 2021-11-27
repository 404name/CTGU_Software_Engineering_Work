package orderSystem.behavior.activity;

import orderSystem.behavior.Activity;

/**
 * @program: algorithm
 * @description:
 * @author: CTGU_LLZ(404name)
 * @create: 2021-11-27 13:15
 **/
public class LowSeason implements Activity {
    public LowSeason() {
    }

    @Override
    public double getActivityDiscount(double price) {
        System.out.println("淡季优惠，半价入住！！");

        double discount = price/2;

        System.out.println("本次享受活动优惠" + discount);

        return price - discount;
    }
}
