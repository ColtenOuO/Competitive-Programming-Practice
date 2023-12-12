fun main()
{
    var q = readLine()!!.toInt()
    for( i in 0 until q )
    {
        var n = readLine()!!.toInt()
        var a = IntArray(n)
        var b = IntArray(n)
        
        var arr = readLine()!!.split(" ").map { it.toInt() }.toMutableList()

        var ok = 1
        var idx1 = 0
        var idx2 = 0
        for( j in 0 until n )
        {
            if( j == 0 )
            {
                continue
            }
            if( arr[j] < arr[j-1] )
            {
                idx1 = j
                idx2 = j - 1
                break
            }
            else if( arr[j] == arr[j-1] )
            {
                arr[j] = arr[j] + 1
            }
        }

        var index = 0
         for( j in 0 until n )
        {
            if( j == idx1 ) continue
            a[index] = arr[j]
            index = index + 1
        }
        index = 0
        for( j in 0 until n )
        {
            if( j == idx2 ) continue
            b[index] = arr[j]
            index = index + 1
        } 

        var ok1 = 1
        var ok2 = 1
        for( j in 0 until n - 1 )
        {
            if( j == 0 ) continue
            if( a[j] < a[j-1] ) ok1 = 0
            if( b[j] < b[j-1] ) ok2 = 0

            if( a[j] == a[j-1] ) a[j] = a[j] + 1
            if( b[j] == b[j-1] ) b[j] = b[j] + 1
        }

        if( ok1 == 1 || ok2 == 1 ) println("YES")
        else println("NO")
    }
}