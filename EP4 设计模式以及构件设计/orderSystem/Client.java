package orderSystem;


import orderSystem.Entity.BusinessRoom;
import orderSystem.Entity.LuxuryRoom;
import orderSystem.behavior.Activity;
import orderSystem.behavior.activity.CommonDay;
import orderSystem.behavior.activity.DoubleEleven;
import orderSystem.behavior.activity.LowSeason;
import orderSystem.behavior.card.ConsumerCard;
import orderSystem.behavior.card.SuperVipCard;
import orderSystem.behavior.card.VipCard;

import java.util.ArrayList;
import java.util.List;

/**
 * @program: Client
 * @description:
 * @author: CTGU_LLZ(404name)
 * @create: 2021-11-27 12:53
 **/
public class Client{
    public static void main(String[] args) {
        /**
         * 商务房：100 分别在 各种情况下销售情况
         */
        new BusinessRoom(new ConsumerCard(),new LowSeason()).getDiscount();

        new BusinessRoom(new VipCard(),new CommonDay()).getDiscount();

        new BusinessRoom(new SuperVipCard(),new DoubleEleven()).getDiscount();
        /**
         * 豪华单间：500 分别在 各种情况下销售情况
         */
        new LuxuryRoom(new ConsumerCard(),new LowSeason()).getDiscount();

        new LuxuryRoom(new VipCard(),new CommonDay()).getDiscount();

        new LuxuryRoom(new SuperVipCard(),new DoubleEleven()).getDiscount();
    }
}
