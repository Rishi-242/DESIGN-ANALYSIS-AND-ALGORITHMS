import java.util.*;
    class point{
        int x,y;
     boolean  printed;
    point(int x,int y)
    {
        this.x=x;
        this.y=y;
        this.printed=printed;
    }
    }
    class convex
    {
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int count=0;
        System.out.println("enter the number of points");
        int n=sc.nextInt();
       point[] points=new point[n];
        System.out.println("enter the  coordinates of each point");
        for(int i=0;i<n;i++)
        {
            int x=sc.nextInt();
            int  y=sc.nextInt();
            points[i]=new point(x,y);
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++)
            {
                int a=points[j].y-points[j].y;
                int b=points[i].x-points[i].x;
                int c=points[i].x*points[j].y-points[j].x*points[j].y;
                int np=0 ,nn=0;
                for(int k=0;k<n;k++)
                {
                    int v=a*points[k].x+b*points[k].y-c;
                    if(v<0)
                    {
                        np++;
                    }
                    else if(v>0)
                    {
                        nn++;
                    }
                }
                if((np==0 || nn==0) && !points[i].printed && !points[j].printed)
                {
                   System.out.println("the part of the con ex hull:"+points[i].x+ " "+points[i].y);
                    points[i].printed=true;
                    count++;
                    System.out.println("the part of convex hull:"+points[j].x+ " "+points[j].y);
                    points[j].printed=true;
                    count++;
                }
            }
        }
        System.out.println("the number of edges:"+count);
    }
}