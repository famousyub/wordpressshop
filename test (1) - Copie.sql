-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Mer 07 Août 2019 à 13:51
-- Version du serveur :  5.6.17
-- Version de PHP :  5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `test`
--

-- --------------------------------------------------------

--
-- Structure de la table `client`
--

CREATE TABLE IF NOT EXISTS `client` (
  `Nom` varchar(100) NOT NULL,
  `Prenom` varchar(100) NOT NULL,
  `Mobile` int(8) NOT NULL,
  `Adresse` varchar(300) NOT NULL,
  `code_fidelite` bigint(200) NOT NULL,
  `Bonus` int(100) NOT NULL,
  `Point` int(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `client`
--

INSERT INTO `client` (`Nom`, `Prenom`, `Mobile`, `Adresse`, `code_fidelite`, `Bonus`, `Point`) VALUES
('ali', 'slimnii', 12457542, 'fjfhj', 1234578, 0, 0),
('ali', 'slimani', 12345678, 'Menzel bouzainne', 14205170, 50, 500),
('Yousef', 'Lefi', 99875452, 'Tunis ', 12345678, 100, 650);

-- --------------------------------------------------------

--
-- Structure de la table `produit`
--

CREATE TABLE IF NOT EXISTS `produit` (
  `CodeAbarre` bigint(200) NOT NULL,
  `Prix` double NOT NULL,
  `Nom` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `produit`
--

INSERT INTO `produit` (`CodeAbarre`, `Prix`, `Nom`) VALUES
(142541522, 1.5, 'adol'),
(74856256, 2.5, 'signal'),
(10, 12, 'major'),
(11, 0.45, 'yaourt'),
(13, 2, 'boite fanta'),
(14, 1.2, 'lait'),
(2147483647, 8.5, 'Axe'),
(2147483647, 1.5, 'Radium'),
(2147483647, 10.5, 'Tlc led'),
(2147483647, 40, 'Cle 3G '),
(4690488015113, 0, ''),
(4690488015113, 12, 'Tlc led'),
(6281006460249, 9.8, 'Axe'),
(4894461473123, 50, 'Cle G3'),
(4008597188466, 2, 'Lampe Radium');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
