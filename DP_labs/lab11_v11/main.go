package main

import (
	"errors"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

const (
	FileName	   = "data.dat"
	MaxFullNameLen = 128
	RecordSize     = 162 // 128 + 12 + 10 + 12
)

// TODO: use separators in binary mode instead of strict block size
type Record struct {
	Number   string // 1-12 digits // TODO: use uint64
	FullName []rune // max size is defined in MaxFullNameLen
	OpenDate string // TODO: use [3]uint16
	Sum      string // 1-12 digits // TODO: use uint64
}

func (r *Record) FillWithUserInput() {
	for {
		var nameInput string
		fmt.Print("Please, enter full name: ")
		if _, err := fmt.Scanf("%s\n", &nameInput); err != nil {
			fmt.Println("There was an error reading name:", err)
			continue
		}

		if len(nameInput) > MaxFullNameLen {
			fmt.Printf("There was an error reading name: full name can't be longer than %d\n", MaxFullNameLen)
			continue
		}

		for i := len(nameInput); i < MaxFullNameLen; i++ {
			nameInput += " "
		}

		r.FullName = []rune(nameInput)
		break
	}

	for {
		var number uint64
		fmt.Print("Please, enter account number (1-12 digits): ")
		if _, err := fmt.Scanf("%d\n", &number); err != nil {
            fmt.Println("There was an error reading account number:", err)
			continue
		}

		converted := strconv.FormatUint(number, 10)
		if len(converted) > 12 { // FIX: magick number
			fmt.Println("There was an error reading account number: account number can't contain > 12 digits")
			continue
		}

		for i := len(converted); i < 12; i++ {
			converted = "0" + converted
		}

		r.Number = converted
		break
	}

	for {
		fmt.Print("Please, enter date of account creation in format DD.MM.YYYY: ")
		var dd, mm uint8
		var yyyy uint16
		if _, err := fmt.Scanf("%d.%d.%d\n", &dd, &mm, &yyyy); err != nil {
			fmt.Println("There was an error reading account creation date:", err)
			continue
		}

		if dd > 31 || mm > 12 || yyyy > 9999 || dd == 0 || mm == 0 || yyyy < 1000 { // TODO: better handling
			fmt.Println("Error: One or more of input values are invalid")
			continue
		}

		if dd < 10 {
			r.OpenDate += "0"
		}
		r.OpenDate += strconv.Itoa(int(dd)) + "."
		if mm < 10 {
            r.OpenDate += "0"
        }
        r.OpenDate += strconv.Itoa(int(mm)) + "."
		r.OpenDate += strconv.Itoa(int(yyyy))

		break
	}

	for {
        var sum uint64
        fmt.Print("Please, enter sum (1-12 digits): ")
        if _, err := fmt.Scanf("%d\n", &sum); err != nil {
            fmt.Println("There was an error reading sum:", err)
            continue
		}

        converted := strconv.FormatUint(sum, 10)
        if len(converted) > 12 { // FIX: magick number
            fmt.Println("There was an error reading sum: sum can't contain > 12 digits")
            continue
        }

        for i := len(converted); i < 12; i++ {
            converted = "0" + converted
        }

        r.Sum = converted
		break
	}
}

func encodeRecord(r Record) []byte {
	var data []byte

	for i := 0; i < MaxFullNameLen; i++ {
		data = append(data, byte(r.FullName[i]))
	}
	data = append(data, []byte(r.Number)...)
	data = append(data, []byte(r.OpenDate)...)
	data = append(data, []byte(r.Sum)...)

	return data
}

func decodeRecord(data []byte) Record {
	r := Record{}
	r.FullName = []rune(string(data[:128]))
	r.Number = string(data[128:140])
	r.OpenDate = string(data[140:150])
	r.Sum = string(data[150:])

	return r
 }

func (r Record) String() string {
	return fmt.Sprintf("%s:\n\tNumber:    %s\n\tOpen date: %s\n\tSum:       %s\n\n", strings.TrimSpace(string(r.FullName)), r.Number, r.OpenDate, r.Sum)
}

func sortRecords(records []Record) {
	sort.Slice(records, func (i, j int) bool {
        return string(records[i].Number) < string(records[j].FullName)
    })
}

func openFile(mode int) *os.File {
	file, err := os.OpenFile(FileName, mode, 0666)
    if err != nil {
        fmt.Println("Error openning file:", err)
        os.Exit(1)
    }

	return file
}

func writeToFile(entries []Record) error {
	file := openFile(os.O_WRONLY)

	for i := 0; i < len(entries); i++ {
		_, err := file.Write(encodeRecord(entries[i]))
		if err != nil {
			return err
		}
	}

	return nil
}

func readFromFile() ([]Record, error) {
	file := openFile(os.O_RDONLY)
	data := make([]byte, 4096) // TODO: dynamic allocation
	entries := []Record{}

	readLen, err := file.Read(data)
	if err != nil {
		return entries, err
	}

	if readLen % RecordSize != 0 {
		return entries, errors.New(fmt.Sprintf("Invalid file length: %d", readLen))
	}

	fmt.Println("Len:", len(data))
	for i := 0; i < readLen; i += RecordSize {
		entries = append(entries, decodeRecord(data[i:i+RecordSize]))
		fmt.Println("decoded")
	}

	return entries, nil
}

func main() {
	entries, err := readFromFile()
	if err != nil {
		fmt.Println("Error reading file:", err)
        os.Exit(1)
	}
	fmt.Println("Read from file:")
	fmt.Println(entries)

	for i := 0; i < 3; i++ {
		r := Record{}
		r.FillWithUserInput()
		entries = append(entries, r)
	}

	fmt.Println(entries)
	fmt.Println("Sorting")
	sortRecords(entries)
	fmt.Println(entries)

	fmt.Println("Writing to file")
	if err := writeToFile(entries); err != nil {
		fmt.Println("Error writing to file:", err)
	}
}
