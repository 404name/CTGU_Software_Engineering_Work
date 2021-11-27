package orderSystem;

import orderSystem.behavior.Activity;
import orderSystem.behavior.Card;


public abstract class Room {

    protected Card card;
    protected Activity activity;

    public Room(Card card, Activity activity) {
        this.card = card;
        this.activity = activity;
    }

    public void getDiscount() {

    }
}
