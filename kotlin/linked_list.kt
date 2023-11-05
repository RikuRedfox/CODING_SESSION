class LinkedList {
    class Node(@Suppress("unused") var data: String) {
        var next: Node? = null
    }

    private var head: Node? = null

    fun insertAtBeginning(name: String) {
        val newNode = Node(name)
        newNode.next = head
        head = newNode
    }

    fun insertAtEnd(name: String) {
        val newNode = Node(name)
        if (head == null) {
            head = newNode
            return
        }
        var current = head
        while (current?.next != null) {
            current = current.next
        }
        current?.next = newNode
    }

    fun insertAtPosition(name: String, position: Int) {
        if (position < 0) {
            println("Invalid position.")
            return
        }
        if (position == 0) {
            insertAtBeginning(name)
            return
        }

        val newNode = Node(name)
        var current = head
        var count = 0
        while (count < position - 1 && current != null) {
            current = current.next
            count++
        }
        if (current == null) {
            println("Invalid position.")
            return
        }
        newNode.next = current.next
        current.next = newNode
    }

    fun deleteFirstNode() {
        if (head != null) {
            head = head?.next
        }
    }

    fun deletedLastNode() {
        if (head == null) {
            return
        }
        if (head?.next == null) {
            head = null
            return
        }
        var current = head
        var prev: Node? = null
        while (current?.next != null) {
            prev = current
            current = current.next
        }
        prev?.next = null
    }

    fun deleteAtPosition(position: Int) {
        if (position < 0 || head == null) {
            println("Invalid position")
            return
        }
        if (position == 0) {
            deleteFirstNode()
            return
        }
        var current = head
        var prev: Node? = null
        var count = 0
        while (count < position && current != null) {
            prev = current
            current = current.next
            count++
        }
        if (current == null) {
            println("Invalid position.")
            return
        }
        prev?.next = current.next
    }

    fun display() {
        var current = head
        while (current != null) {
            print("${current.data} -> ")
            current = current.next
        }
        print("null\n")
    }
}

fun main() {
    val linkedList = LinkedList()
    var choice: Int
    var name: String
    var position: Int

    do {
        println("\nMenu:")
        println("1. Insert at the Beginning")
        println("2. Insert at the End")
        println("3. Insert at the a given position")
        println("4. Delete first node")
        println("5. Delete last node")
        println("6. Delete at a given position")
        println("7. Display")
        println("8. Exit")
        print("Enter your choice: ")
        choice = readlnOrNull()?.toIntOrNull() ?: 0

        when (choice) {
            1 -> {
                print("Enter name to insert at the beginning: ")
                name = readlnOrNull() ?: ""
                linkedList.insertAtBeginning(name)
            }

            2 -> {
                print("Enter name to insert at the end: ")
                name = readlnOrNull() ?: ""
                linkedList.insertAtEnd(name)
            }

            3 -> {
                print("Enter name to insert: ")
                name = readlnOrNull() ?: ""
                print("Enter position: ")
                position = readlnOrNull()?.toIntOrNull() ?: -1
                linkedList.insertAtPosition(name, position)
            }

            4 -> linkedList.deleteFirstNode()

            5 -> linkedList.deletedLastNode()

            6 -> {
                print("Enter position to delete: ")
                position = readlnOrNull()?.toIntOrNull() ?: -1
                linkedList.deleteAtPosition(position)
            }

            7 -> {
                println("Linked List: ")
                linkedList.display()
            }

            8 -> println("Exiting program.")
            else -> println("Out of range. Try again.")
        }
    } while (choice != 8)
}