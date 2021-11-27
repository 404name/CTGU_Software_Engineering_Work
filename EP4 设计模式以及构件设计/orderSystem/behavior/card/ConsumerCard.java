package orderSystem.behavior.card;

import orderSystem.behavior.Card;


/**
 * @program: algorithm
 * @description: 实现类
 * @author: CTGU_LLZ(404name)
 * @create: 2021-11-27 12:50
 **/
public class ConsumerCard implements Card {
    public ConsumerCard() {
    }

    @Override
    public double getDiscount() {
        System.out.println("用户等级：客户| 折扣：无");
        return 1;
    }
}
