package com.juelunn.unit;

/**
 * @program: UnitTesting
 * @description: 疫情等级枚举类
 * @author: CTGU_LLZ(404name)
 * @create: 2021-12-11 16:30
 **/
public enum Grade {
    //枚举数据段，代码风格更美观
    LEVEL_1(2000,Integer.MAX_VALUE,1),
    LEVEL_2(1300,2000,2),
    LEVEL_3(800,1300,3),
    LEVEL_4(500,800,4),
    LEVEL_5(200,500,5),
    LEVEL_6(50,200,6),
    LEVEL_7(0,50,7);

    //成员变量，数据区间起点，数据终点，等级
    private int intervalStart;
    private int intervalEnd;
    private int level;

    Grade(int intervalStart, int lntervalEnd, int level) {
        this.intervalStart = intervalStart;
        this.intervalEnd = lntervalEnd;
        this.level = level;
    }

    public static Grade fromDate(int grade) {
        for (Grade level: Grade.values()) {
            //根据区间返回
            if (grade >= level.getIntervalStart() && grade < level.getIntervalEnd()) {
                return level;
            }
        }
        return null;
    }
    @Override
    public String toString() {
        return "[" + this.intervalStart+"_"+this.intervalEnd + "] 的疫情级别是"  + this.level;
    }
    public int getIntervalStart() {
        return intervalStart;
    }

    public int getIntervalEnd() {
        return intervalEnd;
    }

    public int getLevel() {
        return level;
    }
}
