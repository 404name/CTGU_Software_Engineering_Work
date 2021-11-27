package orderSystem.behavior.card;

import orderSystem.behavior.Card;


/**
 * @program: algorithm
 * @description:
 * @author: CTGU_LLZ(404name)
 * @create: 2021-11-27 12:51
 **/
public class SuperVipCard implements Card {
    public SuperVipCard() {
    }

    @Override
    public double getDiscount() {
        System.out.println("用户等级：金卡| 折扣：8折");
        return 0.8;
    }
}
