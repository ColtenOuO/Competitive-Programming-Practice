import java.util.*
import java.math.*
import kotlin.math.*

fun main()
{
    var q = readLine()!!.toInt()
    for( t in 0 until q )
    {
        var n = readLine()!!.toInt()
        var a = readLine()!!.split(" ").map { it.toLong() }.toMutableList()
        var b = readLine()!!.split(" ").map { it.toLong() }.toMutableList()

        var dp1 = Array<Long>(n+1){0}
        var dp2 = Array<Long>(n+1){0}
        var dp3 = Array<Long>(n+1){0}
        var dp4 = Array<Long>(n+1){0}
        var ans1 = Array<Long>(n+1){0}
        var ans2 = Array<Long>(n+1){0}
        var ans3 = Array<Long>(n+1){0}
        var ans4 = Array<Long>(n+1){0}
        for( i in 0 until n )
        {
            dp1[i] = 0
            dp2[i] = 0
            dp3[i] = 0
            dp4[i] = 0
            if( a[i] < b[i] )
            {
                var tmp = b[i]
                b[i] = a[i]
                a[i] = tmp
            }
        }

    /*    for( i in 0 until n )
        {
            print(a[i])
            print(" ")
        }
        println("")
        for( i in 0 until n )
        {
            print(b[i])
            print(" ")
        }
        println("") */

        var sum1 = 0L
        var sum2 = 0L
        var sum3 = 0L
        var sum4 = 0L

        for( i in 0 until n )
        {
            if( i == 0 )
            {
                dp1[i] = max(a[i],0)
                dp2[i] = max(b[i],0)
            }
            else
            {
                dp1[i] = max(dp1[i-1]+a[i],a[i])
                dp2[i] = max(dp2[i-1]+b[i],b[i])

                if( dp1[i] < 0 ) dp1[i] = 0
                if( dp2[i] < 0 ) dp2[i] = 0
            }

            sum1 = max(sum1,dp1[i])
            sum2 = max(sum2,dp2[i])

            ans1[i] = sum1
            ans2[i] = sum2
        }
        for( i in ( n - 1 ) downTo 0 )
        {
            if( i == n - 1 )
            {
                dp3[i] = max(a[i],0)
                dp4[i] = max(b[i],0)
            }
            else
            {
                dp3[i] = max(dp3[i+1]+a[i],a[i])
                dp4[i] = max(dp4[i+1]+b[i],b[i])

                if( dp3[i] < 0 ) dp3[i] = 0
                if( dp4[i] < 0 ) dp4[i] = 0
            }

            sum3 = max(sum3,dp3[i])
            sum4 = max(sum4,dp4[i])

            ans3[i] = sum3
            ans4[i] = sum4
        }

        var ans = 0L
        for( i in 0 until n )
        {
            var tmp1 = dp1[i]
            if( i + 1 < n ) tmp1 += dp3[i+1]
            
            tmp1 = max(tmp1,ans1[i])
            if( i + 1 < n ) tmp1 = max(tmp1,ans3[i+1])

            var tmp2 = dp2[i]
            if( i + 1 < n ) tmp2 += dp4[i+1]

            tmp2 = max(tmp2,ans2[i])
            if( i + 1 < n ) tmp2 = max(tmp2,ans4[i+1])

            if( i + 1 < n ) ans = max(ans,ans1[i]+ans3[i+1])

            ans = max(ans,tmp1+tmp2)
        }

        println(ans)
    }
}