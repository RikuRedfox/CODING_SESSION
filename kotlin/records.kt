// ! number limit to 11, email @, date of birth format mm/dd/yyyy

data class CustomerRecord(
        val nrcNumber: String,
        val firstName: String,
        val middleName: String,
        val surname: String,
        val phoneNumber: String,
        val dateOfBirth: String,
        val emailAddress: String
)

class CustomerDatabase {
    private val customerRecords = mutableListOf<CustomerRecord>()

    fun addCustomerRecord(customer: CustomerRecord) {
        customerRecords.add(customer)
    }

    fun displayCustomerRecords() {
        for (customer in customerRecords) {
            println("NRC: ${customer.nrcNumber}")
            println("Name: ${customer.firstName} ${customer.middleName} ${customer.surname}")
            println("Phone: ${customer.phoneNumber}")
            println("Date of Birth: ${customer.dateOfBirth}")
            println("Email: ${customer.emailAddress}")
            println()
        }
    }

    fun linearSearchByNrc(nrc: String): CustomerRecord? {
        for (customer in customerRecords) {
            if (customer.nrcNumber == nrc) {
                return customer
            }
        }
        return null
    }

    fun insertionSortByNrc() {
        customerRecords.sortBy(CustomerRecord::nrcNumber)
    }

    fun binarySearchByNrc(nrc: String): CustomerRecord? {
        var left = 0
        var right = customerRecords.size - 1

        while (left <= right) {
            val mid: Int = left + (right - left) / 2
            val midCustomer = customerRecords[mid]

            if (midCustomer.nrcNumber == nrc) {
                return midCustomer
            } else if (midCustomer.nrcNumber < nrc) {
                left = mid + 1
            } else {
                right = mid - 1
            }
        }

        return null
    }
}

fun main() {
    val database = CustomerDatabase()
    var choice: Int

    do {
        println("\nMenu")
        println("1. Enter customer record")
        println("2. Display customer records")
        println("3. Search by NRC (Linear Search)")
        println("4. Sort by NRC (Insertion Sort)")
        println("5. Search by NRC (Binary Search)")
        println("6. Exit")
        print("Enter your choice: ")
        choice = readlnOrNull()?.toIntOrNull() ?: 0

        when (choice) {
            1 -> {
                print("Enter NRC: ")
                val nrc = readlnOrNull() ?: ""
                print("Enter First Name: ")
                val firstName = readlnOrNull() ?: ""
                print("Enter Middle Name: ")
                val middleName = readlnOrNull() ?: ""
                print("Enter Surname: ")
                val surname = readlnOrNull() ?: ""
                print("Enter Phone Number: ")
                val phoneNumber = readlnOrNull() ?: ""
                print("Enter Date of Birth: ")
                val dateOfBirth = readlnOrNull() ?: ""
                print("Enter Email Address: ")
                val emailAddress = readlnOrNull() ?: ""

                val customer = CustomerRecord(
                        nrc,
                        firstName,
                        middleName,
                        surname,
                        phoneNumber,
                        dateOfBirth,
                        emailAddress
                )
                database.addCustomerRecord(customer)
            }

            2 -> {
                println("Customer Records: ")
                database.displayCustomerRecords()
            }

            3 -> {
                print("Enter NRC to search: ")
                val nrc = readlnOrNull() ?: ""
                val customer = database.linearSearchByNrc(nrc)
                if (customer != null) {
                    println("Customer found:")
                    println("NRC: ${customer.nrcNumber}")
                    println("Name: ${customer.firstName} ${customer.middleName} ${customer.surname}")
                    println("Phone: ${customer.phoneNumber}")
                    println("Date of Birth: ${customer.dateOfBirth}")
                    println("Email: ${customer.emailAddress}")
                } else {
                    println("Customer not found.")
                }
            }

            4 -> {
                database.insertionSortByNrc()
                println("Records sorted by NRC (Ascending Order).")
            }

            5 -> {
                print("Enter NRC to search: ")
                val nrc = readlnOrNull() ?: ""
                val customer = database.binarySearchByNrc(nrc)
                if (customer != null) {
                    println("Customer found: ")
                    println("NRC: ${customer.nrcNumber}")
                    println("Name: ${customer.firstName} ${customer.middleName} ${customer.surname}")
                    println("Phone: ${customer.phoneNumber}")
                    println("Date of Birth: ${customer.dateOfBirth}")
                    println("Email: ${customer.emailAddress}")
                } else {
                    println("Customer not found.")
                }
            }

            6 -> println("Exiting program.")

            else -> println("Invalid choice. Please try again.")
        } // when

    } while (choice != 6)
}