package bridge;


import bridge.behavior.FlyBehavior;
import bridge.behavior.SwimBehavior;

public abstract class Bird {
    //组合:能干什么
    protected FlyBehavior flyBehavior;
    protected SwimBehavior swimBehavior;
    public Bird (FlyBehavior behavior,SwimBehavior swimBehavior) {
        this.swimBehavior  = swimBehavior;
        this.flyBehavior = behavior;
    }

    public void display() {
        flyBehavior.fly();
        swimBehavior.swim();
    }
}
