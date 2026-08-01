import sys
from pathlib import Path

import pandas as pd
import matplotlib.pyplot as plt

TIME_COLUMN = "Time_s"
DEMANDED_SPEED_COLUMN = "Demanded_Speed_RPM"
CURRENT_SPEED_COLUMN = "Current_Speed_RPM"

def load_results(csv_file):
    """
    Load the simulation results from a CSV file.

    Args:
        csv_file (str): Path to the CSV file.

    Returns:
        pd.DataFrame: The loaded simulation results.
    """

    
    return pd.read_csv(csv_file)

def create_plot(df, output_file):
    """
    Create a plot of the simulation results.

    Args:
        df (pd.DataFrame): The simulation results DataFrame.
        output_file (str): Path to save the output plot.
    """
    plt.figure(figsize=(10, 6))

    plt.plot(df[TIME_COLUMN], df[DEMANDED_SPEED_COLUMN], label='Demand', color='blue')

    plt.plot(df[TIME_COLUMN], df[CURRENT_SPEED_COLUMN], label='Response', color='orange')

    plt.xlabel("Time [s]")
    plt.ylabel("Speed [RPM]")
    plt.title("Spool Speed Results")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()

    print(f"Saving plot to: {Path(output_file).resolve()}")
    plt.savefig(output_file, dpi=300, bbox_inches='tight')

    plt.close()
    
    print(f"Plot saved to {output_file}")
    print(f"File exists after saving: {Path(output_file).is_file()}")


    

def generate_plot(csv_file):
    df = load_results(csv_file)
    validate_columns(df)
    csv_path = Path(csv_file)
    output_file = csv_path.with_suffix('.png')
    create_plot(df, output_file)
    # Temporary code below
    df = load_results(csv_file)
    print(df.head())
    print(f"Rows: {len(df)}")
    print(f"Columns: {list(df.columns)}")
    print(df.dtypes)
    validate_columns(df)

def validate_columns(df):
    """
    Validate that the required columns are present in the DataFrame.

    Args:
        df (pd.DataFrame): The simulation results DataFrame.

    Raises:
        ValueError: If any required column is missing.
    """
    required_columns = {TIME_COLUMN, DEMANDED_SPEED_COLUMN, CURRENT_SPEED_COLUMN}
    missing_columns = required_columns - set(df.columns)
    if missing_columns:
        raise ValueError(f"Missing required columns: {', '.join(sorted(missing_columns))}")

def main():
    if len(sys.argv) != 2:
        print("Usage: python plot_results.py <path_to_csv_file>")
        sys.exit(1)

    csv_file = Path(sys.argv[1])

    # Check that the file exists
    if not csv_file.is_file():
        print(f"Error: File '{csv_file}' does not exist.")
        sys.exit(1)

    df = load_results(csv_file)
    generate_plot(csv_file)

if __name__ == "__main__":
    main()

