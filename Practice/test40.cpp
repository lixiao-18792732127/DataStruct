int atoi(char *str)  
{  
        if(!str)  
                return -1;  
        bool bMinus=false;  
        int result=0;  
  
        if(('0'>*str || *str>'9')&&(*str=='+'||*str=='-'))  
        {  
               if(*str=='-')  
                bMinus=true;  
               *str++;  
        }  
        while( *str != '\0')  
        {  
                if('0'> *str || *str>'9')  
                        break;  
                else  
                        result = result*10+(*str++ - '0');  
        }  
  
        if (*str != '\0')//no-normal end  
                return -2;  
  
        return bMinus?-result:result;  
} 