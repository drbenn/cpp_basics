<script setup lang="ts">
import { reactive, ref, computed } from 'vue';
import { invoke } from '@tauri-apps/api/core';

// --- Type Definitions for strong typing ---

/**
 * Defines the structure for a single expense record.
 */
interface Expense {
    amount: number | null;
    category: string;
    date: string | undefined;
    description: string;
}

/**
 * Defines the structure for the submission feedback message.
 */
interface SubmissionMessage {
    type: 'success' | 'error';
    text: string;
}

// --- State Management ---

// Reactive state for the form data, strongly typed with the Expense interface
const form: Expense = reactive({
    amount: null,
    category: '',
    date: new Date().toISOString().split('T')[0],
    description: ''
});

// State for UI feedback
const isSubmitting = ref<boolean>(false);
const submitMessage = ref<SubmissionMessage | null>(null);

// Computed property for dynamic button text
const buttonText = computed(() => isSubmitting.value ? 'Processing...' : 'Record Expense');

// --- Methods ---

/**
 * Resets the form fields to their initial state.
 */
const resetForm = () => {
    form.amount = null;
    form.category = '';
    form.date = new Date().toISOString().split('T')[0];
    form.description = '';
};

/**
 * Handles the form submission logic.
 * Calls the Rust backend via Tauri's invoke API.
 */
const submitForm = async () => {
    if (isSubmitting.value) return;

    // Validate that amount is not null
    if (form.amount === null) {
        submitMessage.value = {
            type: 'error',
            text: 'Please enter a valid amount'
        };
        return;
    }

    isSubmitting.value = true;
    submitMessage.value = null;

    try {
        // Call the Rust backend function 'save_expense'
        const result = await invoke<string>('save_expense', {
            amount: form.amount,
            category: form.category,
            date: form.date || new Date().toISOString().split('T')[0],
            description: form.description
        });

        console.log('Expense saved successfully:', result);

        // Show success message
        submitMessage.value = {
            type: 'success',
            text: `Expense of $${form.amount.toFixed(2)} recorded successfully!`
        };

        // Reset form after successful submission
        resetForm();

        // Clear message after 3 seconds
        setTimeout(() => {
            submitMessage.value = null;
        }, 3000);

    } catch (error) {
        console.error('Error saving expense:', error);
        
        submitMessage.value = {
            type: 'error',
            text: `Failed to save expense: ${error}`
        };
    } finally {
        isSubmitting.value = false;
    }
};
</script>

<template>
    <div class="flex items-center justify-center p-4 min-h-screen">
        <!-- Expense Entry Form Container (Styled with Tailwind) -->
        <div class="bg-white p-8 rounded-2xl shadow-xl border border-gray-200 w-full max-w-lg">
            <h1 class="text-3xl font-extrabold text-gray-900 mb-6 text-center">
                <svg class="inline-block w-6 h-6 mr-2 text-emerald-500" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M17 9V7a2 2 0 00-2-2H5a2 2 0 00-2 2v6a2 2 0 002 2h2m2 4h10a2 2 0 002-2v-6a2 2 0 00-2-2H9a2 2 0 00-2 2v6a2 2 0 002 2zm7-5a2 2 0 11-4 0 2 2 0 014 0z"></path></svg>
                Record New Expense
            </h1>
            
            <form @submit.prevent="submitForm" class="space-y-6">
                
                <!-- Amount Input -->
                <div>
                    <label for="amount" class="block text-sm font-medium text-gray-700 mb-1">Amount ($)</label>
                    <input type="number" id="amount" v-model.number="form.amount" step="0.01" required
                           placeholder="e.g., 59.99"
                           class="w-full p-3 border border-gray-300 rounded-xl focus:ring-emerald-500 focus:border-emerald-500 transition duration-150 shadow-sm">
                </div>

                <!-- Category Dropdown -->
                <div>
                    <label for="category" class="block text-sm font-medium text-gray-700 mb-1">Category</label>
                    <select id="category" v-model="form.category" required
                            class="w-full p-3 border border-gray-300 bg-white rounded-xl focus:ring-emerald-500 focus:border-emerald-500 transition duration-150 shadow-sm appearance-none">
                        <option value="" disabled>Select a category</option>
                        <option value="Food">Food & Dining</option>
                        <option value="Transport">Transportation</option>
                        <option value="Utilities">Utilities</option>
                        <option value="Entertainment">Entertainment</option>
                        <option value="Other">Other</option>
                    </select>
                </div>

                <!-- Date Picker -->
                <div>
                    <label for="date" class="block text-sm font-medium text-gray-700 mb-1">Date</label>
                    <input type="date" id="date" v-model="form.date" required
                           class="w-full p-3 border border-gray-300 rounded-xl focus:ring-emerald-500 focus:border-emerald-500 transition duration-150 shadow-sm">
                </div>

                <!-- Description/Notes -->
                <div>
                    <label for="description" class="block text-sm font-medium text-gray-700 mb-1">Notes</label>
                    <textarea id="description" rows="3" v-model="form.description" placeholder="Briefly describe the expense..."
                              class="w-full p-3 border border-gray-300 rounded-xl focus:ring-emerald-500 focus:border-emerald-500 transition duration-150 shadow-sm"></textarea>
                </div>

                <!-- Submit Button -->
                <button type="submit" :disabled="isSubmitting"
                        class="w-full py-3 px-4 text-white font-bold rounded-xl shadow-lg transition duration-200 ease-in-out transform hover:scale-[1.01]"
                        :class="[isSubmitting ? 'bg-gray-400 cursor-not-allowed' : 'bg-emerald-500 hover:bg-emerald-600 focus:ring-4 focus:ring-emerald-300']">
                    {{ buttonText }}
                </button>
                
                <p v-if="submitMessage" class="text-center text-sm font-medium mt-4 p-2 rounded-xl"
                   :class="submitMessage.type === 'success' ? 'bg-green-100 text-green-700' : 'bg-red-100 text-red-700'">
                    {{ submitMessage.text }}
                </p>
            </form>

            <p class="text-center text-xs text-gray-400 mt-6">
                Vue 3 + TypeScript + Tauri (Rust Backend)
            </p>
        </div>
    </div>
</template>

<style scoped>
/* Scoped styles here */
</style>