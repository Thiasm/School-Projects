//
// AREA PROJECT, 2020
// AREA
// File description:
// Action interface
//

export class ActionInterface {
    constructor() {
        this.variables = [];
        this.state = false;
    }

    setState(state) {
        this.state = state;
    }

    getState() {
        return (this.state);
    }

    getVariable(key) {
        return (this.variables[key]);
    }

    setVariable(key, value) {
        this.variables[key] = value;
    }
}
