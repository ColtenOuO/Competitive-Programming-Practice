fun main() {
    var q = readLine()!!.toInt()
    for( i in 0 until q )
    {
        var s = readLine()!!
        var len = s.length

        var num = 0
        var idx = -1

        for( j in (len - 1) downTo 0 )
        {
            if( s[j] != '0' )
            {
                if( s[j] >= '0' && s[j] <= '9' )
                {
                    idx = j
                    break
                }
            }
        }

        for( j in 0 until idx )
        {
            print(s[j])
        }

        println("")
    }
}