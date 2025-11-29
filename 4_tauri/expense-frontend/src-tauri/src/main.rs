// Prevents additional console window on Windows in release
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use serde::{Deserialize, Serialize};

// Define the Expense structure matching your Vue frontend
#[derive(Debug, Serialize, Deserialize)]
struct Expense {
    amount: f64,
    category: String,
    date: String,
    description: String,
}

// Tauri command to save an expense
#[tauri::command]
fn save_expense(amount: f64, category: String, date: String, description: String) -> Result<String, String> {
    // Create the expense object
    let expense = Expense {
        amount,
        category: category.clone(),
        date: date.clone(),
        description: description.clone(),
    };
    
    // Log to console (for debugging)
    println!("Received expense: {:?}", expense);
    
    // Here you would:
    // 1. Save to a database (SQLite, PostgreSQL, etc.)
    // 2. Write to a JSON file
    // 3. Send to an API
    // For now, we'll just return success
    
    Ok(format!(
        "Successfully saved expense: {} - ${:.2} on {}",
        category, amount, date
    ))
}

// Example: Save to JSON file
#[tauri::command]
fn save_expense_to_file(amount: f64, category: String, date: String, description: String) -> Result<String, String> {
    use std::fs::OpenOptions;
    use std::io::Write;
    
    let expense = Expense {
        amount,
        category,
        date,
        description,
    };
    
    // Convert to JSON
    let json = serde_json::to_string_pretty(&expense)
        .map_err(|e| format!("Failed to serialize: {}", e))?;
    
    // Append to file (you'd want to use proper file path handling in production)
    let mut file = OpenOptions::new()
        .create(true)
        .append(true)
        .open("expenses.json")
        .map_err(|e| format!("Failed to open file: {}", e))?;
    
    writeln!(file, "{},", json)
        .map_err(|e| format!("Failed to write: {}", e))?;
    
    Ok(format!("Saved expense of ${:.2}", amount))
}

fn main() {
    tauri::Builder::default()
        .invoke_handler(tauri::generate_handler![save_expense, save_expense_to_file])
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
