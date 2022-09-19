/*
 * BIT_MATH.h
 *
 *  Created on: Aug 21, 2022
 *      Author: Nourhan
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

		/* Set Bit */
#define SET_BIT(REG,BIT_NUM)  REG|=1<<BIT_NUM

		/* Clear Bit */
#define CLR_BIT(REG,BIT_NUM)  REG&=~(1<<BIT_NUM)

		/* Toggle Bit */
#define TGL_BIT(REG,BIT_NUM)  REG^=(1<<BIT_NUM)

		/* GET_BIT */
#define GET_BIT(REG,BIT_NUM)   ((REG>>BIT_NUM)&1)


#endif /* LIB_BIT_MATH_H_ */
