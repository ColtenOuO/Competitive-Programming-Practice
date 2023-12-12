fun update(str: String,index: Int,c: Char): String
{
    val tmp = StringBuilder(str)
    tmp[index] = c
    return tmp.toString()
}
fun main()
{
    var q = readLine()!!.toInt()
    for( i in 0 until q )
    {
        var s = readLine()!!
        var sz = s.length

        var st = 0
        var check = 0
        var ok = 1
        var idx = -1
        var cnt = 0

        for( j in 0 until sz )
        {
            if( s[j] == '+' ) st = st + 1
            else
            {
                st = st - 1
                if( st == -1 )
                {
                    idx = j
                    break
                }
            }
        }

        if( idx == -1 )
        {
            println("1 1")
            continue
        }

        if( ok != 0 )
        {
            var last = 0
            for( j in 0 until sz )
            {
                if( s[j] == '+' )
                {
                    last = j
                }
            }

            s = update(s,idx,'+')
            s = update(s,last,'-')

            var total = 0
            for( j in 0 until sz )
            {
                if( s[j] == '+' ) total = total + 1
                else total = total - 1

                if( total < 0 ) ok = 0
            }

            if( ok == 1 )
            {
                print(idx+1);
                print(" ")
                print(last+1);
                println("");
            }
            else
            {
                println("-1")
            }
        }
    }
}