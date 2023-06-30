import 'dart:convert';
import 'dart:io';

class Task {
  String name;
  String description;
  bool isCompleted;

  Task(
      {required this.name,
      required this.description,
      this.isCompleted = false});

  Map<String, dynamic> toJson() {
    return {
      'name': name,
      'description': description,
      'isCompleted': isCompleted
    };
  }

  factory Task.fromJson(Map<String, dynamic> json) {
    return Task(
      name: json['name'],
      description: json['description'],
      isCompleted: json['isCompleted'] ?? false,
    );
  }
}

void main() {
  List<Task> tasks = [];

  loadTasksFromFile(tasks);

  while (true) {
    print('\n1.) Add task.');
    print('2.) View tasks.');
    print('3.) Mark task as completed.');
    print('4.) Delete task.');
    print('5.) Save tasks and exit.');

    stdout.write('Enter your choice: ');
    String choice = stdin.readLineSync()!;

    switch (choice) {
      case '1':
        addTask(tasks);
        break;
      case '2':
        viewTasks(tasks);
        break;
      case '3':
        markTaskCompleted(tasks);
        break;
      case '4':
        deleteTask(tasks);
        break;
      case '5':
        saveTasksToFile(tasks);
        print('Task saved. Exiting...');
        return;
      default:
        print('Syntax error! Try again.');
    }
  }
}

void addTask(List<Task> tasks) {
  stdout.write('Enter task name: ');
  String name = stdin.readLineSync()!;
  stdout.write('Enter task description: ');
  String description = stdin.readLineSync()!;

  tasks.add(Task(name: name, description: description));

  print('Task added successfully.');
}

void viewTasks(List<Task> tasks) {
  if (tasks.isEmpty) {
    print('No tasks found.');
  } else {
    print('\nTasks: ');
    for (int i = 0; i < tasks.length; i++) {
      Task task = tasks[i];
      String status = task.isCompleted ? '[X]' : '[ ]';
      print('$status ${task.name} - ${task.description}');
    }
  }
}

void markTaskCompleted(List<Task> tasks) {
  if (tasks.isEmpty) {
    print('No tasks found.');
  } else {
    viewTasks(tasks);

    stdout.write('Enter the index of the task to mark as completed: ');
    int index = int.parse(stdin.readLineSync()!);

    if (index >= 0 && index < tasks.length) {
      tasks[index].isCompleted = true;
      print('Task marked as completed.');
    } else {
      print('Invalid task index.');
    }
  }
}

void deleteTask(List<Task> tasks) {
  if (tasks.isEmpty) {
    print('No tasks found.');
  } else {
    viewTasks(tasks);

    stdout.write('Enter the index of the task to delete: ');
    int index = int.parse(stdin.readLineSync()!);

    if (index >= 0 && index < tasks.length) {
      tasks.removeAt(index);
      print('Task deleted successfully.');
    } else {
      print('Invalid task index.');
    }
  }
}

void loadTasksFromFile(List<Task> tasks) {
  try {
    // Open the JSON file
    File file = File('D:/CODING_SESSION/dart/Activity/ToDoList/task.json');
    // Check if the file exists
    if (file.existsSync()) {
      // REad the contents of the file
      String jsonString = file.readAsStringSync();

      // Decode the JSON string into a list of dynamic objects
      List<dynamic> taskData = jsonDecode(jsonString);

      // Iterate over the task data and convert them into Task objects
      for (dynamic data in taskData) {
        if (data is Map<String, dynamic>) {
          tasks.add(Task.fromJson(data));
        }
      }
      print('Tasks loaded from file.');
    }
  } catch (e) {
    print('Error loading tasks from file: $e');
  }
}

void saveTasksToFile(List<Task> tasks) {
  try {
    // Covert the list of Task objects into a list of JSON maps
    List<Map<String, dynamic>> taskData =
        tasks.map((task) => task.toJson()).toList();

    // Encode the list of maps into a JSON string
    String jsonString = jsonEncode(taskData);

    // Open the JSON file for writing
    File file = File('D:/CODING_SESSION/dart/Activity/ToDoList/task.json');
    
    // Write the JSON string to the file
    file.writeAsStringSync(jsonString);

    print('Tasks saved to file.');
  } catch (e) {
    print('Error saving tasks to file: $e');
  }
}
