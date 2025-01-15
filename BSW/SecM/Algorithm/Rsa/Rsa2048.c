/*============================================================================
 *  Copyright (C) 2009-2019, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  file       < Rsa2048.c >
 *  brief      < Compute SHA256 hash value source file >
 *
 *  < Compiler: Tasking     MCU:TC23X >
 *
 *  author     < houcheng.ge >
 *  date       < 2019-05-07 >
 *
 *============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>       <REVISION LOG>
 *  V1.0.0       20190507  houcheng.ge    Initial version
 */
/*============================================================================*/

#include "Rsa2048.h"
#include "appl.h"

DefLintBuff(z,64);

DefLintBuff(m,64);

DefLintBuff(n,64);/*n = p * q*/

DefLintBuff(e,1);/*public key*/


tLongIntData M; 
tLongIntData N; 
tLongIntData E; 
tLongIntData C; 


typedef enum
{
    CeCmpR_Equ = 0,
    CeCmpR_Larg,
    CeCmpR_Litt
}teCmpResult;

static teCmpResult lint_cmp(const tLongIntData a,const tLongIntData b);
static void lint_mov(tLongIntData *pa,tLongIntData b);
static void lint_mul(const tLongIntData a,const tLongIntData b,tLongIntData* pc);
/*static void lint_add(const tLongIntData a,const tLongIntData b,tLongIntData* pc);*/
static void lint_mod(tLongIntData a,tLongIntData b,tLongIntData *pc);
/*static void lint_euclid(tLongIntData a,tLongIntData b,tLongIntData *pc);
static void lint_div(const tLongIntData a,const tLongIntData b,tLongIntData* pc);*/
static void lint_sub(const tLongIntData a,const tLongIntData b,tLongIntData* pc);


/******************************************************************************/
/**
 * @brief               <Data Init>
 *
 * <Data Init> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/

void tLongIntDataInit(void)
{
	tLongIntData M1 = {ConfgData(m,GetBaseintSize(m))};
	tLongIntData N1 = {ConfgData(n,GetBaseintSize(n))};
	tLongIntData E1 = {ConfgData(e,1)};
	tLongIntData C1 = {ConfgData(z,64)};

	M.baseintmaxsize = M1.baseintmaxsize;
	M.baseintrealsize = M1.baseintrealsize;
	M.pbignum = M1.pbignum;

	N.baseintmaxsize = N1.baseintmaxsize;
	N.baseintrealsize = N1.baseintrealsize;
	N.pbignum = N1.pbignum;

	E.baseintmaxsize = E1.baseintmaxsize;
	E.baseintrealsize = E1.baseintrealsize;
	E.pbignum = E1.pbignum;

	C.baseintmaxsize = C1.baseintmaxsize;
	C.baseintrealsize = C1.baseintrealsize;
	C.pbignum = C1.pbignum;

	e[0] = 0x00010001;
}
/******************************************************************************/
/**
 * @brief				<Calculation>
 *
 * 						<Get real size> .
 * Service ID	:		<NONE>
 * Sync/Async	:		<Synchronous>
 * Reentrancy			<Reentrant>
 * @param[in]			<pa(IN)>
 * @param[out]			<pa(OUT)>
 * @param[in/out]		<NONE>
 * @return				<NONE>
 */
/******************************************************************************/

static void set_realsize(tLongIntData *pa)
{
    SIZE_TYPE i;

	/*Get real size*/
    for(i=pa->baseintrealsize - 1u; i > 0u; i--)
    {
        if(pa->pbignum[i] != 0u)
        {
            break;
        }
    }
    pa->baseintrealsize = i + 1u;
}

/******************************************************************************/
/**
 * @brief				<Compare>
 *
 * 						<Data comparison> .
 * Service ID	:		<NONE>
 * Sync/Async	:		<Synchronous>
 * Reentrancy			<Reentrant>
 * @param[in]			<a(IN) b(IN)>
 * @param[out]			<NONE>
 * @param[in/out]		<NONE>
 * @return				<result>
 */
/******************************************************************************/

static teCmpResult lint_cmp(const tLongIntData a,const tLongIntData b)
{   
    SIZE_TYPE i,l1,l2;
    teCmpResult result = CeCmpR_Equ;
    
    l1 = a.baseintrealsize;
    l2 = b.baseintrealsize;
    if (l1 > l2)/* a > b*/
    {
        result = CeCmpR_Larg;   
    }
    else if(l1 < l2)/* a < b*/
    {
        result = CeCmpR_Litt;   
    }
    else	/* a = b*/
    {
        i=l1;
        while(i >= 1u)
        {
            i--;
			/* a and b Maximum number comparison */
            if ((a.pbignum)[i] > (b.pbignum)[i])
            {
                result = CeCmpR_Larg;
                break;
            }
            else if ((a.pbignum)[i] < (b.pbignum)[i])
            {
                result = CeCmpR_Litt;   
                break;
            }
            else
            {
            	/* empty */
            }
        }

    }
    return result;
}

/******************************************************************************/
/**
 * @brief				<Calculation>
 *
 *						 <move from b to a> .
 * Service ID	:		<NONE>
 * Sync/Async	:		<Synchronous>
 * Reentrancy			<Reentrant>
 * @param[in]			<pa(IN) b(IN)>
 * @param[out]			<NONE>
 * @param[in/out]		<NONE>
 * @return				<NONE>
 */
/******************************************************************************/

static void lint_mov(tLongIntData *pa,tLongIntData b)
{
    SIZE_TYPE i;

    /*move from b to a*/
    if(pa->baseintmaxsize >= b.baseintrealsize)
    {
        pa->baseintrealsize = b.baseintrealsize;
    
    	if(pa->pbignum != b.pbignum)
    	{
	        for(i=0;i<b.baseintrealsize;i++)
	        {
	            pa->pbignum[i]=b.pbignum[i];
	        }		
    	}

    }

}

/******************************************************************************/
/**
 * @brief				<Calculation>
 *
 * 						<Data multiplication> .
 * Service ID	:		<NONE>
 * Sync/Async	:		<Synchronous>
 * Reentrancy			<Reentrant>
 * @param[in]			<a(IN) b(IN) pc(IN)>
 * @param[out]			<pc(OUT)>
 * @param[in/out]		<NONE>
 * @return				<NONE>
 */
/******************************************************************************/
static void lint_mul(const tLongIntData a,const tLongIntData b,tLongIntData* pc)
{
    if((pc->pbignum != a.pbignum) && (pc->pbignum != b.pbignum))
	{
		SIZE_TYPE i = 0, j = 0, l1 = 0, l2 = 0;
		MAXINT_TYPE sum,mul,carry;

		l1=a.baseintrealsize;
		l2=b.baseintrealsize;

		pc->baseintrealsize = l1+l2 - 1u;
		carry=0;
		for(i=0;i<pc->baseintrealsize;i++)
		{
            #if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
                Appl_wdTriggerFct();
            #endif
			sum=carry;
			carry = 0;
			for(j=0;j<l2;j++)
			{
			    if ((i >= j) && ((i - j) < l1))
			    {
			        mul = (MAXINT_TYPE)a.pbignum[i-j]*b.pbignum[j];
			        carry += GetHiWord(mul);
			        sum+= GetLoWord(mul);
			    }
			}
			carry+=GetHiWord(sum);
			pc->pbignum[i]=GetLoWord(sum);

		}
		if(carry!=0u)
		{
			pc->pbignum[i] = GetLoWord(carry);
			pc->baseintrealsize++;
		}

	}
}

/******************************************************************************/
/**
 * @brief				<Calculation>
 *
 * 						<Data addition> .
 * Service ID	:		<NONE>
 * Sync/Async	:		<Synchronous>
 * Reentrancy			<Reentrant>
 * @param[in]			<a(IN) b(IN) pc(IN)>
 * @param[out]			<pc(OUT)>
 * @param[in/out]		<NONE>
 * @return				<NONE>
 */
/******************************************************************************/
#if 0
static void lint_add(const tLongIntData a,const tLongIntData b,tLongIntData* pc)
{
    SIZE_TYPE i,l1,l2,size,end;
    const BASEINT_TYPE *ptmp;
    BASEINT_TYPE carry=0;
    MAXINT_TYPE sum;
    l1=a.baseintrealsize;
    l2=b.baseintrealsize;

	/*real size comparison*/
    if(l1 < l2)
    {
        size = l1;
        end =l2;
        ptmp = b.pbignum;
    }
    else
    {
        size = l2;
        end =l1;
        ptmp = a.pbignum;
    }

	/*Sum of big numbers*/
    for(i=0;i<size;i++)
    {
         sum = (MAXINT_TYPE)a.pbignum[i]+b.pbignum[i] + carry;
         carry = GetHiWord(sum);
         pc->pbignum[i] = GetLoWord(sum);
    }

	/*High and low byte accumulation*/
    while(i<end)
    {
         sum = (MAXINT_TYPE)carry + ptmp[i];
         carry = GetHiWord(sum);
         pc->pbignum[i] = GetLoWord(sum);
         i++;
    }
        
    if(carry != 0u)
    {
        pc->pbignum[i] = carry;
        pc->baseintrealsize = i+1u;
    }
    else
    {
        pc->baseintrealsize = i;
    }
    set_realsize(pc);

}               
#endif

/******************************************************************************/
/**
 * @brief				<Calculation>
 *
 * 						<Data subtraction> .
 * Service ID	:		<NONE>
 * Sync/Async	:		<Synchronous>
 * Reentrancy			<Reentrant>
 * @param[in]			<a(IN) b(IN) pc(IN)>
 * @param[out]			<pc(OUT)>
 * @param[in/out]		<NONE>
 * @return				<NONE>
 */
/******************************************************************************/
static void lint_sub(const tLongIntData a,const tLongIntData b,tLongIntData* pc)
{
    SIZE_TYPE i,size,end;
    BASEINT_TYPE carry;
    MAXINT_TYPE sum;
    
    size = b.baseintrealsize;
    end = a.baseintrealsize;
    carry=0;
    for(i=0;i<size;i++)
    {
        sum = (MAXINT_TYPE)b.pbignum[i] + carry;
        if((MAXINT_TYPE)a.pbignum[i] >= sum)
        {
            pc->pbignum[i]=a.pbignum[i]-b.pbignum[i]-carry;
            carry=0;
        }
        else
        {
            pc->pbignum[i]= (BASEINT_TYPE)(R_UINT + a.pbignum[i]-b.pbignum[i]-carry);
            carry=1;
        }
    }

	/*big number Compare*/
   	while(i<end)
    {
        if(a.pbignum[i] >= carry)
        {
            pc->pbignum[i] = a.pbignum[i] - carry;
            carry = 0;
        }
        else
        {
            pc->pbignum[i] = BSINT_MAX;
            carry = 1u;
        }
        i++;
    }

    pc->baseintrealsize = i;
    set_realsize(pc);

}

/******************************************************************************/
/**
 * @brief				<Calculation>
 *
 * 						<Data division> .
 * Service ID	:		<NONE>
 * Sync/Async	:		<Synchronous>
 * Reentrancy			<Reentrant>
 * @param[in]			<a(IN) b(IN) pc(IN)>
 * @param[out]			<pc(OUT)>
 * @param[in/out]		<NONE>
 * @return				<NONE>
 */
/******************************************************************************/
#if 0
static void lint_div(const tLongIntData a,const tLongIntData b,tLongIntData* pc)
{
    BASEINT_TYPE singdata = 1;
    DefLintBuff(Abuff, MAX_SIZE);
    DefLintBuff(Bbuff, MAX_MULSIZE);
    DefLintBuff(Xbuff, MAX_SIZE);
    DefLintBuff(Ybuff, MAX_SIZE);   
    
    tLongIntData A,B,X,Y,S;

    SIZE_TYPE i,len;
    MAXINT_TYPE num,div_temp;

    S.baseintmaxsize = 1;
    S.baseintrealsize = 1;
    S.pbignum = &singdata;
    
    InitIntStruct(A, Abuff);
    InitIntStruct(B, Bbuff);
    InitIntStruct(X, Xbuff);
    InitIntStruct(Y, Ybuff);    
    
    Xbuff[0] = 0u;
    X.baseintrealsize = 1u;
    
    lint_mov(&A,a);
    
    while(lint_cmp(A,b) != CeCmpR_Litt)
    {       
		div_temp = A.pbignum[A.baseintrealsize-1u];
		num = b.pbignum[b.baseintrealsize-1u];
		len = A.baseintrealsize - b.baseintrealsize;
		if((div_temp == num)&&(len== 0u))
		{
		    lint_add(X,S,&X);
		    break;
		}
		if((div_temp <= num) && (len != 0u))
		{
            len--;
            div_temp = (div_temp << GET_BITLEN(BSINTBYT_LEN)) + A.pbignum[A.baseintrealsize - 2u];
		}
		div_temp = div_temp/(num+1u);

		Ybuff[0] = GetLoWord(div_temp);
		Ybuff[1] = GetHiWord(div_temp);
		if(Ybuff[1] != 0u)
		{
		    Y.baseintrealsize = 2u;
		}
		else
		{
		    Y.baseintrealsize = 1u;
		}
		
		if(len != 0u)
		{
			Y.baseintrealsize+=len;
			for(i=Y.baseintrealsize-1u;i>=len;i--)
			{
                Y.pbignum[i]=Y.pbignum[i-len];
			}
			for(i=0;i<len;i++)
			{
				Y.pbignum[i]=0u;
			}
		}
		lint_add(X,Y,&X);
		lint_mul(Y,b,&B);
		lint_sub(A,B,&A);
    }
    lint_mov(pc,X);
}
#endif

/******************************************************************************/
/**
 * @brief				<Calculation>
 *
 * 						<mod operation> .
 * Service ID	:		<NONE>
 * Sync/Async	:		<Synchronous>
 * Reentrancy			<Reentrant>
 * @param[in]			<a(IN) b(IN) pc(IN)>
 * @param[out]			<pc(OUT)>
 * @param[in/out]		<NONE>
 * @return				<NONE>
 */
/******************************************************************************/

static void lint_mod(tLongIntData a,tLongIntData b,tLongIntData *pc)
{
	if(pc->pbignum != a.pbignum)
	{
		DefLintBuff(Xbuff, MAX_MULSIZE);   
		DefLintBuff(multbuff, MAX_MULSIZE);   

		tLongIntData X;

		tLongIntData mult;
		SIZE_TYPE i,len;
		MAXINT_TYPE num,div_temp;
		InitIntStruct(X,Xbuff);
		InitIntStruct(mult,multbuff);
		lint_mov(pc,a);/*A = a*/

		while(lint_cmp(*pc,b) != CeCmpR_Litt)
		{ 
			div_temp = pc->pbignum[pc->baseintrealsize - 1u];
			num = b.pbignum[b.baseintrealsize - 1u];
			len = pc->baseintrealsize -b.baseintrealsize;
			
			if((div_temp == num)&&(len == 0u))
			{
				lint_sub(*pc,b,pc);
				break;
			}
			if((div_temp<=num) && (len != 0u))
			{
				len--;
				div_temp = (div_temp << GET_BITLEN(BSINTBYT_LEN))+pc->pbignum[pc->baseintrealsize - 2u];
			}
			div_temp = div_temp/(num + 1u);

            X.pbignum[0u] = GetLoWord(div_temp);
            X.pbignum[1] = GetHiWord(div_temp);
            if( X.pbignum[1] != 0u)
            {
      			X.baseintrealsize = 2u;
            }
            else
            {
      			X.baseintrealsize = 1u;
            }
			lint_mul(X,b,&mult);
			lint_mov(&X,mult);
			
			if(len != 0u)
			{
				X.baseintrealsize += len;
				for(i=X.baseintrealsize -1u;i>=len;i--)
				{
		        	X.pbignum[i]=X.pbignum[i-len];
				}
				for(i=0;i<len;i++)
				{
		            X.pbignum[i]=0u;
				}
			}
			lint_sub(*pc,X,pc);
		}
	}

}

/******************************************************************************/
/**
 * @brief				<Calculation>
 *
 * 						<Data division> .
 * Service ID	:		<NONE>
 * Sync/Async	:		<Synchronous>
 * Reentrancy			<Reentrant>
 * @param[in]			<a(IN) pc(IN)>
 * @param[out]			<pc(OUT)>
 * @param[in/out]		<NONE>
 * @return				<NONE>
 */
/******************************************************************************/

static void lint_div2(tLongIntData a,tLongIntData * pc)
{
    BASEINT_TYPE tmpdata;
    SIZE_TYPE i,l;

    l = a.baseintrealsize - 1u;
    for(i = 0; i < l; i++)
    {
        tmpdata = (a.pbignum[i+1u] << (GET_BITLEN(BSINTBYT_LEN) - 1u));
        pc->pbignum[i] = (tmpdata | (a.pbignum[i] >> 1u));
    }
    pc->pbignum[l] = a.pbignum[l] >> 1u;

    if(pc->pbignum[l] == 0u )
    {
        pc->baseintrealsize = l; 
    }
    else
    {
        pc->baseintrealsize = l + 1u;
    }

}

/******************************************************************************/
/**
 * @brief				<Calculation>
 *
 * 						<X=y^a MOD b> .
 * Service ID	:		<NONE>
 * Sync/Async	:		<Synchronous>
 * Reentrancy			<Reentrant>
 * @param[in]			<y(IN) a(IN) b(IN) pc(IN)>
 * @param[out]			<pc(OUT)>
 * @param[in/out]		<NONE>
 * @return				<NONE>
 */
/******************************************************************************/
void lint_pwrmd(tLongIntData y,tLongIntData a,tLongIntData b,tLongIntData *pc)
{
	tLongIntData mult;
	
	DefLintBuff(tmpbuff, MAX_MULSIZE);
	DefLintBuff(Abuff, MAX_SIZE);
	DefLintBuff(Ybuff, MAX_MULSIZE);
	DefLintBuff(multbuff, MAX_MULSIZE);

    BASEINT_TYPE singdata = 1u;

    tLongIntData tmp,A,Y,S;
    
    S.baseintmaxsize = 1u;
    S.baseintrealsize = 1u;
    S.pbignum = &singdata;
    
    InitIntStruct(mult,multbuff);
    InitIntStruct(tmp,tmpbuff);
    InitIntStruct(A,Abuff);
    InitIntStruct(Y,Ybuff);
	
    lint_mov(&tmp, S);
    lint_mov(&A,a);
    lint_mov(&Y,y);
    lint_mod(Y,b,&mult);
    lint_mov(&Y,mult);
    while(lint_cmp(A,S) == CeCmpR_Larg)/*A > 1*/
    {
        #if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
            Appl_wdTriggerFct();
        #endif
        if((A.pbignum[0] & 0x01u) != 0u)
        {
            lint_mul(tmp,Y,&mult);
            lint_mod(mult,b,&tmp);
        }
        lint_mul(Y,Y,&mult);
        lint_mod(mult,b,&Y);
        lint_div2(A,&A);    
    }
    lint_mul(tmp,Y,&mult);
    lint_mod(mult,b,&tmp);
    lint_mov(pc,tmp);	
}

/******************************************************************************/
/**
 * @brief				<Calculation>
 *
 * 						<ax-by=1,b >> a> .
 * Service ID	:		<NONE>
 * Sync/Async	:		<Synchronous>
 * Reentrancy			<Reentrant>
 * @param[in]			<a(IN) b(IN) pc(IN)>
 * @param[out]			<pc(OUT)>
 * @param[in/out]		<NONE>
 * @return				<NONE>
 */
/******************************************************************************/
#if 0
static void lint_euclid(tLongIntData a,tLongIntData b,tLongIntData *pc)
{
    boolean x = 1,y = 1;
    DefLintBuff(tmpbuff, MAX_MULSIZE);
    DefLintBuff(Abuff, MAX_SIZE);
    DefLintBuff(Bbuff, MAX_SIZE);
    DefLintBuff(Ebuff, MAX_SIZE);
    DefLintBuff(Xbuff, MAX_SIZE);
    DefLintBuff(Ybuff, MAX_MULSIZE);    
    
    tLongIntData tmp,A,B,Edata,X,Y;

    InitIntStruct(tmp, tmpbuff);
    InitIntStruct(A, Abuff);
    InitIntStruct(B, Bbuff);
    InitIntStruct(Edata, Ebuff);
    InitIntStruct(X, Xbuff);
    InitIntStruct(Y, Ybuff);

	/*move from a to A*/
    lint_mov(&A,a);
	/*move from b to B*/
    lint_mov(&B,b);

    Xbuff[0] = 0;
    Ybuff[0] = 1;
    X.baseintrealsize = 1;
    Y.baseintrealsize = 1;
    
    while((A.baseintrealsize!=1u)||(A.pbignum[0]!=0u))
    {
        lint_div(B,A,&Edata);
        lint_mul(A,Edata,&tmp);
        lint_sub(B,tmp,&tmp);
        lint_mov(&B,A);
        lint_mov(&A,tmp);
        lint_mov(&tmp,Y);
        lint_mul(Y,Edata,&Y);
    	if(x == y)
    	{
    	    if(lint_cmp(X,Y) != CeCmpR_Litt)
    	    {
                lint_sub(X,Y,&Y);
    	    }
    	    else
    	    {
                lint_sub(Y,X,&Y);
                y = 0;
    	    }
    	}
    	else
    	{
			lint_add(X,Y,&Y);

			if(x == 0u)
			{
				x = 1u;
			}
			else
			{
				x = 0u;
			}

			if(y == 0u)
			{
				y = 1u;
			}
			else
			{
				y = 0u;
			}
    	}
        lint_mov(&X,tmp);
        
    }
    if(x == 0u)
    {
        lint_sub(A,X,&X);
    }
    lint_mov(pc,X);
}
#endif

