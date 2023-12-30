int fibo(int n)
{
    int f1=1,f2=1,f=0;
    if(n==1)return 1;
    else{
    while(f<n)
    {
        f=f1+f2;
        if(f==n)return 1;
        else
        {
            f1=f2;
            f2=f;
        }
    }}
    return 0;
}
int chinhphuong(int n)
{
    int i;
    for(i=1;i*i<=n;i++)
    {
        if((i*i)== n)return 1;
    }
    return 0;
}
int xetsonguyento(int n)
{
    if(n<2)return 0;
    else if(n==2)return 1;
    else
    {
        int i;
        for(i=2;i<n;i++)
        {
            if(n%i==0)return 0;
            else continue;
        }
        return 1;
    }
    return 1;
}
int uoc(int n)
{
    int i,p=0;
    for(i=1;i<n;i++)
    {
        if(n%i==0)p=i;
    }
    return p;
}
int sontgannhat(int n)
{
    int i,p;
    for(i=2;i<n;i++)
    {
        if(xetsonguyento(i)==1)
            p=i;
    }
    return p;
}
int lientiep(int array[],int size)
{
    int i,k,a[size],max=1,min,d=1;
    for(i=0;i<size;i++)
    {
        a[i]=array[i];
    }

    for(i=0;i<size;i++)
    {
        min=a[i];
        for(k=i+1;k<size;k++)
        {
            if(a[k]<min)
            {
                min=a[k];
                a[k]=a[i];
                a[i]=min;
            }
        }
    }

    for(i=1;i<size;i++)
    {

        if(a[i]-a[i-1]==1)d++;
        else d=1;
        if(d>max)max=d;
    }
    if(max==1)max=0;
    return max;

}
int fibogannhat(int n)
{
    int i,p=0;
    for(i=1;i<n;i++)
    {
        if(fibo(i)==1)p=i;
    }
    return p;
}
void voldemort(int r,int id,int *hp,int*m,int array[],int i,int dua)
{
    int hpmax;
    if(id==1)hpmax=999;
    else if(id==2)hpmax=900;
    else if(id==3)hpmax=888;
    else if(id==4)hpmax=777;
    if(id==1 && dua!=0)
    {
        *hp=999;
        *m=999;
    }
    else if(fibo(i+1)==1)
    {
        int h1=(i+1)%(100+r);
        int h2=array[i]%(100+r);
        if(h1>=h2)
        {
            *hp=hpmax;
            *m=999;
        }
        else *hp=0;
    }
    else *hp=0;
}
void snape(int id,int* hp, int* m,int aotanghinh,int* dua)
{
    if(aotanghinh==0)
    {
        if(id==4)*hp=0;
        else if(id==1)
        {
            *hp=999;
            *m=999;
            *dua=1;
        }
        else
        {
            *hp=fibogannhat(*hp);
        }
    }
}
void bellatrix(int r,int* hp,int* m,int array[],int size,int i,int *tslg,int aotanghinh)
{
    if(aotanghinh==0)
    {
        int h1=(i+1)%(100+r);
        int h2=array[i]%(100+r);
        if(h1>=h2)
        {
            *m=*m+array[i];
            if(*m>999)*m=999;
            *tslg=*tslg-1;
            if(*tslg<0)*tslg=0;
        }
        else
        {
            *hp=*hp-array[i];
            if(*hp<0)*hp=0;
            int q=lientiep(array,size);
            *tslg=*tslg-q;
            if(*tslg<0)*tslg=0;
        }
    }
}
void khonglo(int r, int id,int* hp,int* m,int array[],int i,int aotanghinh)
{
    if(aotanghinh==0)
    {
        int x=array[i]%100;
        if((id==2 || id==4) && xetsonguyento(x)==1 && xetsonguyento(*hp)==1){}
        else
        {
            int h1=(i+1)%(100+r);
            int h2=array[i]%(100+r);
            if(h1>=h2){}
            else
            {
                int q=uoc(x);
                if(q==0)q=1;
                *hp=*hp-q;
                *m=*m-q;
                if(*hp<0)*hp=0;
                if(*m<0)*m=0;
            }
        }
    }
}
void nhansu(int r, int array[],int i, int* tslg,int* aotanghinh)
{
    if(*aotanghinh==0)
    {
        int h1=(i+1)%(100+r);
        int h2=array[i]%(100+r);
        if(h1>=h2)
        {
            *aotanghinh=1;
        }
        else
        {
            *tslg=0;
        }
    }
}
void muggle(int *m,int n)
{
    int i,x;
    for(i=0;i<n;i++)
    {
        if(chinhphuong(i)==1)x=i;
    }
    *m=x;
}
void truan(int r,int id,int* hp,int *m)
{
    if(id==3)
    {
        if(r<3){}
        else
        {
            int p=sontgannhat(r);
            if(*hp+(*m/p)<=888)
            {
                *hp=*hp+(*m/p);
                *m=*m%p;

            }
            else
            {
                *m=*hp+(*m/p)-888+(*m%p);
                *hp=888;
            }
        }
    }
    else
    {
        int hpmax;
        if(id==1)hpmax=999;
        else if(id==2)hpmax=900;
        else hpmax=777;

        if(*hp+*m<=hpmax)
        {
            *hp=*hp+*m;
            *m=0;
        }
        else
        {
            *m=*hp+*m-hpmax;
            *hp=hpmax;
        }
    }
}
void tttt(int r, int id, int *hp, int *m, int array[], int i, int aotanghinh)
{

    int h1=(i+1)%(100+r);
    int h2=array[i]%(100+r);
    if(h1>=h2)
    {
        *m=*m+array[i];
        if(*m>999)*m=999;
    }
    else
    {
        if(aotanghinh==0)
        {
            if((id==1)&& xetsonguyento(h2)==1 && h2>*m)
            {
                *hp=*hp-array[i];
                if(*hp<0)*hp=0;
            }
            else if(id==1)
            {
                *m=*m+array[i];
                if(*m>999)*m=999;
            }
            else
            {
                *hp=*hp-array[i];
                if(*hp<0)*hp=0;
            }
        }
    }
}
int sukien(int r, int n, int id, int* m, int array[],int size,int* hp,int* aotanghinh,int* tslg,int* dua,int i)
{
    if(array[i]==0)
    {
        *tslg=*tslg+1;
        if(*tslg==n)
        {
            return 0;
        }
        return 1;
    }
    else if(array[i]>=100 && array[i]<=199)
    {
        tttt(r,id,hp,m,array,i,*aotanghinh);
        if(*hp==0) return 2;
        else return 1;
    }
    else if(array[i]==1)
    {
        truan(r,id,hp,m);
        return 1;
    }
    else if(array[i]>=200 && array[i]<=299)
    {
        if(*aotanghinh==0)
        {
            int x=array[i]%100;
            if((*m-x)<=4 && (i<2))
            {
                return 3;
            }
            else if((*m-x) <=4)
            {
                return 4;
            }
            else
            {
                muggle(m,*m-x);
                return 1;
            }
        }

    }
    else if(array[i]>=300 && array[i]<=399)
    {
        nhansu(r,array,i,tslg,aotanghinh);
        return 1;
    }
    else if(array[i]>=500 && array[i]<=599)
    {
        khonglo(r,id,hp,m,array,i,*aotanghinh);
        if(*hp==0)return 2;
        else return 1;
    }
    else if(array[i]==666)
    {
        bellatrix(r,hp,m,array,size,i,tslg,*aotanghinh);
        if(*hp==0)return 2;
        else return 1;
    }
    else if(array[i]==777)
    {
        snape(id,hp,m,*aotanghinh,dua);
        if(*hp==0)return 2;
        else return 1;
    }
    else
    {
        voldemort(r,id,hp,m,array,i,*dua);
        if(*hp==0)return 2;
        else return 1;
    }
    return 1;

}
void journey(int r, int n, int id, int m, int array[],int size)
{
    int hp, aotanghinh=0, tslg=0, dua=0;
    if(id==1)hp=999;
    else if(id==2)hp=900;
    else if(id==3)hp=888;
    else hp=777;
     int i=0,result;
     for(i=0;i<size;i++)
     {
         result=sukien(r,n,id,&m,array,size,&hp,&aotanghinh,&tslg,&dua,i);
        if(result==0)
        {
            printf("%d",hp+m);
            break;
        }
        else if(result==1)
        {
            if(i==size-1)
            {
                printf("0");
                break;
            }
            else continue;
        }
        else if(result==2)
        {
            printf("-1");
            break;
        }
        else if(result==3)
        {
            printf("0");
            break;
        }
        else if (result==4)
        {
            i=i-2;
            result=sukien(r,n,id,&m,array,size,&hp,&aotanghinh,&tslg,&dua,i);
            if(result==0)
            {
                printf("%d",hp+m);
                break;
            }
            else if(result==1)
            {
                continue;
            }
            else if(result==2)
            {
                printf("-1");
                break;
            }
            else if(result==3)
            {
                printf("0");
                break;
            }
            i=i+1;
            result=sukien(r,n,id,&m,array,size,&hp,&aotanghinh,&tslg,&dua,i);
            if(result==0)
            {
                printf("%d",hp+m);
                break;
            }
            else if(result==1)
            {
                continue;
            }
            else if(result==2)
            {
                printf("-1");
                break;
            }
            else if(result==3)
            {
                printf("0");
                break;
            }
            i=i+1;
     }
}
}