import java.io.File
import java.util.*
import kotlin.collections.ArrayList

var tokenizer: StringTokenizer? = null
val inputFile = File("cond.in").bufferedReader()

fun nextToken(): String {
    while (tokenizer == null || !tokenizer!!.hasMoreTokens())
        tokenizer = StringTokenizer(inputFile.readLine())
    return tokenizer!!.nextToken()
}

fun nextInt(): Int = nextToken().toInt()

fun dfs(adjacencyList: Array<Vector<Int>>, startVertex: Int, vertexesUsed: BooleanArray, topList: ArrayList<Int>) {
    vertexesUsed[startVertex] = true
    for (vertex in adjacencyList[startVertex])
        if (!vertexesUsed[vertex])
            dfs(adjacencyList, vertex, vertexesUsed, topList)
    topList.add(startVertex)
}

fun dfs(adjacencyList: Array<Vector<Int>>, startVertex: Int, components: IntArray, componentCount: Int) {
    components[startVertex] = componentCount
    for (vertex in adjacencyList[startVertex])
        if (components[vertex] == 0)
            dfs(adjacencyList, vertex, components, componentCount)
}

fun main() {
    val vertexes = nextInt()
    val edges = nextInt()

    val adjacencyList = Array<Vector<Int>>(vertexes) { Vector() }
    val adjacencyTransList = Array<Vector<Int>>(vertexes) { Vector() }
    val vertexesUsed = BooleanArray(vertexes) { false }
    val components = IntArray(vertexes) { 0 }

    for (i in 0 until edges) {
        val a = nextInt() - 1
        val b = nextInt() - 1
        adjacencyList[a].add(b)
        adjacencyTransList[b].add(a)
    }

    val topList = ArrayList<Int>()
    for (i in 0 until vertexes)
        if (!vertexesUsed[i])
            dfs(adjacencyList, i, vertexesUsed, topList)
    topList.reverse()

    var componentCount = 1
    for (vertex in topList) {
        if (components[vertex] == 0)
            dfs(adjacencyTransList, vertex, components, componentCount++)
    }

    val outputFile = File("condt.out").printWriter()
    outputFile.println(componentCount-1)
    for (component in components)
        outputFile.print("$component ")
    outputFile.close()
}