package com.juelunn.unit;

import static org.junit.jupiter.api.Assertions.*;
/**
 * @program: UnitTesting
 * @description:
 * @author: CTGU_LLZ(404name)
 * @create: 2021-12-11 16:42
 **/
class GradeTest {
    @org.junit.jupiter.api.Test
    void fromDate() {
        /**
         * 采用路径覆盖测试，从0-2100依次测试
         */
        int grade = 0;
        while(grade < 2100){
            Grade level = Grade.fromDate(grade);
            System.out.println(grade + "对应区间" + level);
            grade += 100;
        }
    }
}
