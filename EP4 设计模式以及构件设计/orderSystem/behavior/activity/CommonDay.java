package orderSystem.behavior.activity;

import orderSystem.behavior.Activity;

/**
 * @program: algorithm
 * @description:
 * @author: CTGU_LLZ(404name)
 * @create: 2021-11-27 13:15
 **/
public class CommonDay implements Activity {
    public CommonDay() {
    }

    @Override
    public double getActivityDiscount(double price) {
        System.out.println("日常，当前暂无活动");

        double discount = 0;

        System.out.println("本次享受活动优惠" + discount);

        return price - discount;
    }
}
