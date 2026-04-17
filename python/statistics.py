class StatisticsCalculator:
    def __init__(self, data):
        self.data = data

    def calculate_mean(self):
        return sum(self.data) / len(self.data)

    def calculate_median(self):
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        if n % 2 == 1:
            return float(sorted_data[n // 2])
        return (sorted_data[n // 2 - 1] + sorted_data[n // 2]) / 2.0

    def calculate_mode(self):
        freq = {}
        for num in self.data:
            freq[num] = freq.get(num, 0) + 1
        max_freq = max(freq.values())
        return sorted([k for k, v in freq.items() if v == max_freq])

    def display_results(self):
        print(f"Data: {self.data}")
        print(f"Mean: {self.calculate_mean():.2f}")
        print(f"Median: {self.calculate_median():.2f}")
        modes = self.calculate_mode()
        print(f"Mode: {', '.join(map(str, modes))}")


if __name__ == "__main__":
    data = [4, 7, 2, 7, 1, 3, 4, 7, 2, 9]
    calc = StatisticsCalculator(data)
    calc.display_results()
