# Protein Translation

Translate RNA sequences into proteins.

RNA can be broken into three nucleotide sequences called codons, and then translated to a polypeptide like so:

RNA: "AUGUUUUCU" => translates to

Codons: "AUG", "UUU", "UCU" => which become a polypeptide with the following sequence =>

Protein: "Methionine", "Phenylalanine", "Serine"

There are 64 codons which in turn correspond to 20 amino acids; however, all of the codon sequences and resulting amino acids are not important in this exercise. If it works for one codon, the program should work for all of them. However, feel free to expand the list in the test suite to include them all.

There are also three terminating codons (also known as 'STOP' codons); if any of these codons are encountered (by the ribosome), all translation ends and the protein is terminated.

All subsequent codons after are ignored, like this:

1. RNA: "AUGUUUUCUUAAAUG"

2. Codons: "AUG", "UUU", "UCU", "UAA", "AUG" =>

3. Protein: "Methionine", "Phenylalanine", "Serine"

Note the stop codon "UAA" terminates the translation and the final methionine is not translated into the protein sequence.

Below are the codons and resulting Amino Acids needed for the exercise.

|Codon|Protein|
|---|---|
|AUG|Methionine|
|UUU, UUC|Phenylalanine|
|UUA, UUG|Leucine|
|UCU, UCC, UCA, UCG|Serine|
|UAU, UAC|Tyrosine|
|UGU, UGC|Cysteine|
|UGG|Tryptophan|
|UAA, UAG, UGA|STOP|

## Example

```cpp
proteins("AUGUUUUCUUAAAUG") == {"Methionine", "Phenylalanine", "Serine"}
```

## Installation/Usage

[See the ExercismPractice README for general usage and installation details.](https://github.com/Lignite17/ExercismPractice/blob/main/README.md)

## License
[MIT](https://choosealicense.com/licenses/mit/)
