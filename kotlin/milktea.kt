import java.text.SimpleDateFormat
import java.util.*

const val CLEAR_TERMINAL = "\u001b[H\u001b[2J"
fun main() {
    Order().runProgram()
}

data class MilkteaOrder(val flavor: String, val size: String, val price: Int)

class Order {
    companion object {
        val FLAVOR_NAME = listOf(
                "Mango            ",
                "Vanilla          ",
                "Cookies and Cream",
                "Coffee           ",
                "Almond           ",
                "Nutella          ",
                "Choco            ",
                "Mocha            ",
                "Cheesecake       ",
                "Caramel          "
        )
        val SIZES = listOf("S", "M", "L")
        val PRICES = listOf(30, 60, 90)
    }

    private val orderID = generateOrderID()
    private var totalOrders = 0
    private var totalPrice = 0.0
    private var payment = 0.0

    private val orders = ArrayList<MilkteaOrder>()

    fun runProgram() {
        println("Welcome to Andrew's Milktea Shop!")

        totalOrders = getIntInput("How many orders would you like? (MAX 10)") { value ->
            value in 1..10
        }

        printMenu()
        printOrder()

        totalPrice = calculateTotalPrice()
        println("Total: ${String.format("%.2f", totalPrice)}")

        payment = getDoubleInput("Enter your payment: ") { value ->
            value >= totalPrice
        }

        printReceipt()
    }

    private fun printMenu() {
        println(CLEAR_TERMINAL)
        println("""
            SIZE            PRICES
            [1] Small       30 Php
            [2] Medium      60 PHP
            [3] Large       90 Php
        """.trimIndent())

        for ((index, flavorNames) in FLAVOR_NAME.withIndex()) {
            println("${index + 1}) $flavorNames")
        }

        return getOrder()
    }

    private fun getOrder() {
        for (i in 0 until totalOrders) {
            println("\nNumber Order > ${i + 1}")

            val flavorID = getIntInput("Enter the Flavor ID (1-10)") { value ->
                value in 1..10
            }

            val sizeID = getIntInput("Enter the Size ID (1-3)") { value ->
                value in 1..3
            }

            val order = MilkteaOrder(
                    flavor = FLAVOR_NAME[flavorID - 1],
                    size = SIZES[sizeID - 1],
                    price = PRICES[sizeID - 1]
            )
            orders.add(order)
        }
    }

    private fun printReceipt() {
        println(CLEAR_TERMINAL)
        println(Date())
        println("Order ID: $orderID")
        println()
        printOrder()
        println()
        println("TOTAL: ${String.format("%.2f", totalPrice)}")
        println("CASH: $payment")
        println("CHANGE: ${String.format("%.2f", payment - totalPrice)}")
    }

    private fun printOrder() {
        for (order in orders) {
            println("Flavor: ${order.flavor} | Price[Size]: ${order.price}[${order.size}]")
        }
    }

    private fun calculateTotalPrice(): Double {
        return orders.fold(0.0) { total, order -> total + order.price }
    }

    private fun getIntInput(prompt: String, validation: ((Int) -> Boolean)? = null): Int {
        while (true) {
            try {
                print("$prompt > ")
                val input = readln()
                val value = input.toIntOrNull()
                @Suppress("SameParameterValue")
                if (value != null && (validation == null || validation(value))) {
                    return value
                }
                println("Invalid input. Try again.")
            } catch (e: NumberFormatException) {
                println("Error: $e")
            }
        }
    }

    private fun getDoubleInput(@Suppress("SameParameterValue") prompt: String, validation: ((Double) -> Boolean)? = null): Double {
        while (true) {
            try {
                print("$prompt > ")
                val input = readln()
                val value = input.toDoubleOrNull()
                if (value != null && (validation == null || validation(value))) {
                    return value
                }
                println("Invalid input. Try again.")
            } catch (e: NumberFormatException) {
                println("Error: $e")
            }
        }
    }

    private fun generateOrderID():String {
        val dateFormat = SimpleDateFormat("yyyyMMdd", Locale.getDefault())
        val currentDate = dateFormat.format(Date())
        val randomNumber = Random().nextInt(1000) + 1
        return  "$currentDate$randomNumber"
    }
}