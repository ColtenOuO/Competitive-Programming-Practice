fun main()
{
    var q = readLine()!!.toInt()
    for( i in 0 until q )
    {
        var n = readLine()!!.toInt()
        var arr = Array(2) { CharArray(n) { ' ' } }

        for( x in 0 until 2 )
        {
            var s = readLine()!!
            for( y in 0 until n )
            {
                arr[x][y] = s[y]
            }
        }

        var ans = 0
        for( x in 0 until 2 )
        {
            for( y in 0 until n )
            {
                if( arr[x][y] == '*' ) ans = ans + 1
            }
        }

        for( x in 0 until 2 )
        {
            for( y in 0 until n )
            {
                if( arr[x][y] == '*' )
                {
                    if( x - 1 >= 0 && arr[x-1][y] == '#' )
                    {
                        arr[x-1][y] = '.'
                        arr[x][y] = '#'
                    }
                    else if( x + 1 < 2 && arr[x+1][y] == '#' )
                    {
                        arr[x+1][y] = '.'
                        arr[x][y] = '#'
                    }
                    else if( y - 1 >= 0 && arr[x][y-1] == '#' )
                    {
                        arr[x][y-1] = '.'
                        arr[x][y] = '#'
                    }
                    else if( y + 1 < n && arr[x][y+1] == '#' )
                    {
                        arr[x][y+1] = '.'
                        arr[x][y] = '#'
                    }
                    else
                    {
                        arr[x][y] = '#'
                        ans = ans - 1
                    }
                }
            }
        }

        println(ans)
    }
}