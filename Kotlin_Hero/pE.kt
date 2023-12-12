fun main()
{
    var q = readLine()!!.toInt()
    for( t in 0 until q )
    {
        var n = readLine()!!.toInt()
        var a = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
        var b = readLine()!!.split(" ").map { it.toInt() }.toMutableList()

        var c = a
        var d = b

        for( i in 0 until n )
        {
            if( a[i] < b[i] )
            {
                var tmp = a[i]
                a[i] = b[i]
                b[i] = tmp
            }
            if( c[i] > d[i] )
            {
                var tmp = c[i]
                c[i] = d[i]
                d[i] = tmp
            }
        }

        var total1 = 0
        var total2 = 0
        var mx1 = 0
        var mx2 = 0

        var mx4 = 0
        var mx3 = 0
        var total3 = 0
        var total4 = 0
        for( i in 0 until n )
        {
            total1 = total1 + a[i]
            total2 = total2 + b[i]
            total3 = total3 + c[i]
            total4 = total4 + d[i]

            if( total1 < 0 ) total1 = 0
            if( total2 < 0 ) total2 = 0
            if( total3 < 0 ) total3 = 0
            if( total4 < 0 ) total4 = 0

            if( mx1 < total1 ) mx1 = total1
            if( mx2 < total2 ) mx2 = total2
            if( mx3 < total3 ) mx3 = total3
            if( mx4 < total4 ) mx4 = total4
        }

        if( mx1 + mx2 > mx3 + mx4 ) println(mx1+mx2)
        else println(mx3+mx4)
    }
}