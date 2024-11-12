//
// EPITECH PROJECT, 2020
// AREA
// File description:
// localStorage
//

export function addToLocalStorage(title, value) {
    localStorage.setItem(title, value);
}

export function getValueFromLocalStorage(title) {
    return (localStorage.getItem(title));
}

export function clearLocalStorage() {
    localStorage.clear();
}
